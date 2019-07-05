#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_ponto.h"
#include "arquivo.h"
#include "sa.h"

#define RAIO_AUMENTO 0.30
#define TEMP_INICIAL 100
#define TEMP_FINAL 10
#define RESFRIAMENTO 0.1
#define MODO_SAIDA 0
/* Define o de Saida do resultado - 0 = Resultado da Iteração; 1 = Resultado para Estatistica; */

struct resultado {
    Ponto ponto;
    int demanda;
};
typedef struct resultado Resultado;

void busca_solucao_sa(Lista_Ponto lista_ponto, int ponto_coberto[]);
void solucao_inicial(Lista_Ponto lista_ponto, Resultado *solucao, int ponto_coberto[]);
void solucao_inicial(Lista_Ponto lista_ponto, Resultado *solucao, int ponto_coberto[]);
int avalia_solucao(Lista_Ponto agrupamento);
Lista_Ponto calcula_agrupamento(Lista_Ponto lista_ponto, Ponto ponto, int ponto_coberto[]);
Lista_Ponto calcula_agrupamento_especial(Lista_Ponto lista_ponto, Ponto ponto);
void preenche_ponto_coberto(Lista_Ponto lista_ponto, Ponto ponto, int ponto_coberto[], int facilidade);
void despreenche_ponto_coberto(Lista_Ponto lista_ponto, Ponto ponto, int ponto_coberto[], int facilidade);
void reseta_ponto_coberto(int ponto_coberto[], int tamanho);
void armazena_resultado(Resultado *resultado, Resultado *solucao, int tamanho);

Resultado *overall; /* Melhor Solução de todas; */
Resultado *solucao;
float temperatura;
int m = 0;

int sa(Lista_Ponto lista_ponto, char *arq_saida) {
    int i, pop = 0;
    int ponto_coberto[lista_ponto->tamanho]; /* Flag para os pontos que já estão dentro da cobertura; */
    char string[100];
    
    overall = (Resultado*) malloc(lista_ponto->facilidade * sizeof(Resultado));
    solucao = (Resultado*) malloc(lista_ponto->facilidade * sizeof(Resultado));
    
    reseta_ponto_coberto(ponto_coberto, lista_ponto->tamanho); /* Inicializa vetor de flag; */
    solucao_inicial(lista_ponto, solucao,  ponto_coberto); /* Inicializa facilidades em pontos aleatorios; */
    armazena_resultado(overall, solucao, lista_ponto->facilidade);
    temperatura = TEMP_INICIAL;
    while (temperatura > TEMP_FINAL) { /* Testa se a temperatura atual atingiu o limite esperado; */
        busca_solucao_sa(lista_ponto, ponto_coberto);
    }
    if (!MODO_SAIDA) { /* Modo Resultado; */
        for (i = 0; i < lista_ponto->facilidade; i++) { /* Mostra e Salva Resultado; */
            printf("X: %d - Y: %d - Pop: %d\n", overall[i].ponto->x, overall[i].ponto->y, overall[i].demanda);
            sprintf(string, "X: %d - Y: %d - Pop: %d\n", overall[i].ponto->x, overall[i].ponto->y, overall[i].demanda);
            escreve_arquivo(arq_saida, string);
            pop += overall[i].demanda;
        }
        printf("Pop. Tot Abrangida: %d de %d\n", pop, lista_ponto->populacao);   
        sprintf(string, "Pop. Tot. Abrangida: %d de %d\n", pop, lista_ponto->populacao);
        escreve_arquivo(arq_saida, string);
    }
    else {
        for (i = 0; i < lista_ponto->facilidade; i++) { /* Mostra e Salva Resultado; */
            pop += overall[i].demanda;
        }
    }
    
    for (i = 0; i < lista_ponto->facilidade; i++) { /* Desaloca Memoria; */
        free(overall[i].ponto);
        free(solucao[i].ponto);
    }
    free(overall);
    free(solucao);
    return(pop);
}
 
void busca_solucao_sa(Lista_Ponto lista_ponto, int ponto_coberto[]) { /* Função por rodadas. A cada rodada, é feito um movimento com cada Facilidade; */
    Lista_Ponto agrupamento, agrupamento_temp;
    Ponto ponto_temp;
    double sorteado, criterio;
    int i, j, demanda, demanda_solucao = 0, demanda_overall = 0;
    temperatura -= (temperatura * RESFRIAMENTO); /* Decrementa Temperatura; */
    if (!MODO_SAIDA) {
        printf("%f\n", temperatura);
    }
    for (i = 0; i < lista_ponto->facilidade; i++) { /* Faz um movimento com cada Facilidade; */
        despreenche_ponto_coberto(lista_ponto, solucao[i].ponto, ponto_coberto, i);
        agrupamento = calcula_agrupamento(lista_ponto, solucao[i].ponto, ponto_coberto);
        for (j = 0; j < agrupamento->tamanho; j++) {
            ponto_temp = retorna_ponto(agrupamento, j);
            agrupamento_temp = calcula_agrupamento(lista_ponto, ponto_temp, ponto_coberto);
            demanda = avalia_solucao(agrupamento_temp);
            if (demanda > solucao[i].demanda) {
                solucao[i].demanda = demanda;
                solucao[i].ponto = ponto_temp;
            }
            destroi_lista_ponto(agrupamento_temp);
        }
        preenche_ponto_coberto(lista_ponto, solucao[i].ponto, ponto_coberto, i);
    }
    for (i = 0; i < lista_ponto->facilidade; i++) {
        demanda_solucao += solucao[i].demanda;
        demanda_overall += overall[i].demanda;
    }
    if (demanda_solucao > demanda_overall) { /* Se houver melhora no resultado */
        armazena_resultado(overall, solucao, lista_ponto->facilidade);
    }
    else { /* Criterio de aceitação de Boltzmann; */ 
        for (i = 0; i < lista_ponto->facilidade; i++) { /* Faz um movimento com cada Facilidade; */
            agrupamento = calcula_agrupamento_especial(lista_ponto, solucao[i].ponto);
            j = rand() % agrupamento->tamanho; /* Pega um ponto Aleatorio; */
            ponto_temp = retorna_ponto(agrupamento, j);
            despreenche_ponto_coberto(lista_ponto, solucao[i].ponto, ponto_coberto, i);
            agrupamento_temp = calcula_agrupamento(lista_ponto, ponto_temp, ponto_coberto);
            demanda = avalia_solucao(agrupamento_temp);
            criterio = exp(-((solucao[i].demanda / 1000) - (demanda / 1000)) / (temperatura));
            sorteado = (double)rand() / (double)RAND_MAX;
            if (sorteado < criterio) {
                solucao[i].demanda = demanda;
                solucao[i].ponto = ponto_temp;
            }
            preenche_ponto_coberto(lista_ponto, solucao[i].ponto, ponto_coberto, i);
        }
    }
    return;
}

void solucao_inicial(Lista_Ponto lista_ponto, Resultado *solucao, int ponto_coberto[]) {
    Lista_Ponto agrupamento;
    Ponto ponto;
    int i, ponto_posicao, demanda = 0;
    for (i = 0; i < lista_ponto->facilidade; i++) {
        solucao[i].ponto = (Ponto) malloc(sizeof(struct ponto));
        ponto_posicao = rand() % lista_ponto->tamanho; /* Sorteia Aleatoriamente uma posição; */
        ponto = retorna_ponto(lista_ponto, ponto_posicao);
        agrupamento = calcula_agrupamento(lista_ponto, ponto, ponto_coberto);
        preenche_ponto_coberto(lista_ponto, ponto, ponto_coberto, i);
        demanda = avalia_solucao(agrupamento); /* Avalia população atendida; */
        solucao[i].ponto->x = ponto->x;
        solucao[i].ponto->y = ponto->y;
        solucao[i].ponto->demanda = ponto->demanda;
        solucao[i].ponto->proximo = NULL;
        solucao[i].demanda = demanda;
        destroi_lista_ponto(agrupamento); /* Destroi lista auxiliar; */
    }
    return;
}

int avalia_solucao(Lista_Ponto agrupamento) {
    int i, qualidade = 0;
    Ponto aux;
    for (i = 0; i < agrupamento->tamanho; i++) {
        aux = retorna_ponto(agrupamento, i);
        qualidade += aux->demanda;
    }
    return(qualidade);
}

/* Verifica quais pontos estão dentro do raio de ação da Facilidade; */
Lista_Ponto calcula_agrupamento(Lista_Ponto lista_ponto, Ponto ponto, int ponto_coberto[]) {
    Lista_Ponto agrupamento;
    agrupamento = cria_lista_ponto(0, 1, lista_ponto->raio);
    Ponto aux;
    double distancia;
    int i, j = 0;
    for (i = 0; i < lista_ponto->tamanho; i++) {
        aux = retorna_ponto(lista_ponto, i);
        distancia = sqrt(pow((ponto->x - aux->x), 2) + pow((ponto->y - aux->y), 2));
        if ((distancia <= lista_ponto->raio) && (ponto_coberto[i] == -1)) {
            insere_ponto(agrupamento, aux->x, aux->y);
            insere_demanda(agrupamento, aux->demanda, j);
            j++;
        }
    }
    agrupamento->tamanho = j;
    return(agrupamento);
}

/* Cria um agrupamento com Raio aumentado em x% para uso no S.A.; */
Lista_Ponto calcula_agrupamento_especial(Lista_Ponto lista_ponto, Ponto ponto) {
    Lista_Ponto agrupamento;
    agrupamento = cria_lista_ponto(0, 1, lista_ponto->raio);
    Ponto aux;
    double distancia;
    int i, j = 0, raio;
    raio = lista_ponto->raio + (lista_ponto->raio * RAIO_AUMENTO);
    for (i = 0; i < lista_ponto->tamanho; i++) {
        aux = retorna_ponto(lista_ponto, i);
        distancia = sqrt(pow((ponto->x - aux->x), 2) + pow((ponto->y - aux->y), 2));
        if (distancia <= raio) {
            insere_ponto(agrupamento, aux->x, aux->y);
            insere_demanda(agrupamento, aux->demanda, j);
            j++;
        }
    }
    agrupamento->tamanho = j;
    return(agrupamento);
}

/* Preenche o vetor dos pontos que ja foram cobertos por uma soluçao anterior; */
void preenche_ponto_coberto(Lista_Ponto lista_ponto, Ponto ponto, int ponto_coberto[], int facilidade) {
    Ponto aux;
    double distancia;
    int i;
    for (i = 0; i < lista_ponto->tamanho; i++) {
        aux = retorna_ponto(lista_ponto, i);
        distancia = sqrt(pow((ponto->x - aux->x), 2) + pow((ponto->y - aux->y), 2));
        if (distancia <= lista_ponto->raio && ((ponto_coberto[i] == -1) || (ponto_coberto[i] == facilidade))) {
            ponto_coberto[i] = facilidade;
        }
    }
    return;
}

void despreenche_ponto_coberto(Lista_Ponto lista_ponto, Ponto ponto, int ponto_coberto[], int facilidade) {
    Ponto aux;
    double distancia;
    int i;
    for (i = 0; i < lista_ponto->tamanho; i++) {
        aux = retorna_ponto(lista_ponto, i);
        distancia = sqrt(pow((ponto->x - aux->x), 2) + pow((ponto->y - aux->y), 2));
        if (distancia <= lista_ponto->raio && (ponto_coberto[i] == facilidade)) {
            ponto_coberto[i] = -1;
        }
    }
    return;
}

void reseta_ponto_coberto(int ponto_coberto[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        ponto_coberto[i] = -1;
    }
    return;
}

void armazena_resultado(Resultado *resultado, Resultado *solucao, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        resultado[i].ponto = (Ponto) malloc(sizeof(struct ponto));
        resultado[i].ponto->x = solucao[i].ponto->x;
        resultado[i].ponto->y = solucao[i].ponto->y;
        resultado[i].ponto->demanda = solucao[i].ponto->demanda;
        resultado[i].ponto->proximo = NULL;
        resultado[i].demanda = solucao[i].demanda;
    }
    return;
}
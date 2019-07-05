#include <stdio.h>
#include <stdlib.h>

#include "lista_ponto.h"

Lista_Ponto cria_lista_ponto(int tamanho, int facilidade, int raio) {
    Lista_Ponto lista_ponto;
    lista_ponto = (Lista_Ponto) malloc(sizeof(struct lista_ponto));
    lista_ponto->tamanho = tamanho;
    lista_ponto->facilidade = facilidade;
    lista_ponto->raio = raio;
    lista_ponto->populacao = 0;
    lista_ponto->inicio = NULL;
    return(lista_ponto);
}

void destroi_lista_ponto(Lista_Ponto lista_ponto) {
    Ponto aux;
    aux = lista_ponto->inicio;
    while (aux != NULL) {
	lista_ponto->inicio = aux->proximo;
	free(aux);
	aux = lista_ponto->inicio;
    }
    free(lista_ponto);
    lista_ponto = NULL;
    return;
}

void insere_ponto(Lista_Ponto lista_ponto, int x, int y) {
    Ponto ponto, aux;
    ponto = (Ponto) malloc(sizeof(struct ponto));
    ponto->x = x;
    ponto->y = y;
    ponto->demanda = 0;
    ponto->proximo = NULL;
    if (lista_ponto->inicio == NULL) { /* Caso inicial - Lista_Ponto vazia; */
    	lista_ponto->inicio = ponto;
	return;
    }
    aux = lista_ponto->inicio; /* Inserir no final da lista_ponto; */
    while (aux->proximo != NULL) {
	aux = aux->proximo;
    }
    aux->proximo = ponto;
    return;
}

void insere_demanda(Lista_Ponto lista_ponto, int demanda, int pos) {
    Ponto aux;
    int i = 0;
    aux = lista_ponto->inicio;
    while (i != pos) {
        aux = aux->proximo;
        i++;
    }
    aux->demanda = demanda;
    lista_ponto->populacao += demanda;
    return;
}

Ponto retorna_ponto(Lista_Ponto lista_ponto, int pos) {
    Ponto aux;
    int i = 0;
    aux = lista_ponto->inicio;
    while (aux != NULL) {
        if (i == pos) { /* Verifica se são iguais; */
            return(aux);
        }
        aux = aux->proximo;
        i++;
    }
    return(NULL);
}
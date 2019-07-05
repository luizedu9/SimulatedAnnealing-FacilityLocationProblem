#ifndef LISTA_H
#define LISTA_H

struct ponto {
    int x;
    int y;
    int demanda;
    struct ponto *proximo;
};

struct lista_ponto {
    int tamanho;
    int facilidade;
    int raio; /* Em metros; */
    int populacao;
    struct ponto *inicio;
};

typedef struct lista_ponto *Lista_Ponto;
typedef struct ponto *Ponto;

Lista_Ponto cria_lista_ponto(int tamanho, int facilidade, int raio);
void destroi_lista_ponto(Lista_Ponto lista_ponto);
void insere_ponto(Lista_Ponto lista_ponto, int x, int y);
void insere_demanda(Lista_Ponto lista_ponto, int demanda, int pos);
Ponto retorna_ponto(Lista_Ponto lista_ponto, int pos);

#endif /* LISTA_H */
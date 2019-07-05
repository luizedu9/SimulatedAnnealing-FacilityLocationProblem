#include <stdio.h>
#include <stdlib.h>
#include "lista_ponto.h"
#include "arquivo.h"

Lista_Ponto le_arquivo_ponto(char *arquivo) {
    FILE *arq;
    Lista_Ponto lista_ponto;
    char linha[100], aux[100];
    int i, j, tamanho, facilidade, raio, x, y;
    arq = fopen(arquivo, "r");
    if (arq == NULL) {
        printf("ERRO - Arquivo SJCxxx.dat");
        exit(0);
    }
    fgets(linha, sizeof(linha), arq); /* Pega primeira linha */
    i = j = 0;
    /* Pega tamanho; */
    while ((linha[i] != ' ') && (linha[i] != '\0') && (linha[i] != '\r') && (linha[i] != '\n')) { /* Quando encontrar espaço, fim de linha ou tabulação, termina um parametro; */
        aux[j] = linha[i];
        i++;
        j++;
    }
    aux[j] = '\0';
    tamanho = atoi(aux);
    i++;
    j = 0;
    /* Pega Facilidades; */
    while ((linha[i] != ' ') && (linha[i] != '\0') && (linha[i] != '\r') && (linha[i] != '\n')) { /* Quando encontrar espaço, fim de linha ou tabulação, termina um parametro; */
        aux[j] = linha[i];
        i++;
        j++;
    }
    aux[j] = '\0';
    facilidade = atoi(aux);
    i++;
    j = 0;
    /* Pega Raio; */
    while ((linha[i] != ' ') && (linha[i] != '\0') && (linha[i] != '\r') && (linha[i] != '\n')) { /* Quando encontrar espaço, fim de linha ou tabulação, termina um parametro; */
        aux[j] = linha[i];
        i++;
        j++;
    }
    aux[j] = '\0';
    raio = atoi(aux);
    lista_ponto = cria_lista_ponto(tamanho, facilidade, raio);
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        i = j = 0;
        /* Pega X; */
        while ((linha[i] != ' ') && (linha[i] != '\0') && (linha[i] != '\r') && (linha[i] != '\n')) { /* Quando encontrar espaço, fim de linha ou tabulação, termina um parametro; */
            aux[j] = linha[i];
            i++;
            j++;
        }
        aux[j] = '\0';
        x = atoi(aux);
        i++;
        j = 0;
        /* Pega Y; */
        while ((linha[i] != ' ') && (linha[i] != '\0') && (linha[i] != '\r') && (linha[i] != '\n')) { /* Quando encontrar espaço, fim de linha ou tabulação, termina um parametro; */
            aux[j] = linha[i];
            i++;
            j++;
        }
        aux[j] = '\0';
        y = atoi(aux);
        insere_ponto(lista_ponto, x, y);
    }
    fclose(arq);
    return(lista_ponto);
}

Lista_Ponto le_arquivo_demanda(Lista_Ponto lista_ponto, char *arquivo) {
    FILE *arq;
    char linha[100];
    int i = 0, demanda;
    arq = fopen(arquivo, "r");
    if (arq == NULL) {
        printf("ERRO - Arquivo demand_SJCxxx.dat");
        exit(0);
    }
    while ((fgets(linha, sizeof(linha), arq)) != NULL) {
        demanda = atoi(linha);
        insere_demanda(lista_ponto, demanda, i);
        i++;
    }
    return(lista_ponto);
}

void inicia_arquivo(char *arquivo) {
    FILE *arq;
    arq = fopen(arquivo, "w");
    fclose(arq);
}

void escreve_arquivo(char *arquivo, char *string) {
    FILE *arq;
    arq = fopen(arquivo, "a");
    fprintf(arq, "%s", string);
    fclose(arq);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_ponto.h"
#include "arquivo.h"
#include "sa.h"

/* PARA RECEBER O RESULTADO, USE ESTE */
/*
int main(int argc, char **argv) {
    if (argc == 4) {
        srand((unsigned)time(NULL));
        Lista_Ponto lista_ponto;
        lista_ponto = le_arquivo_ponto(argv[1]);
        lista_ponto = le_arquivo_demanda(lista_ponto, argv[2]);
        inicia_arquivo(argv[3]);
        sa(lista_ponto, argv[3]);
        destroi_lista_ponto(lista_ponto);
    }
    else {
        printf("ERRO - PARAMETRO");
    }
    return(0);
}
*/


/******************************************************************************************/

/* PARA RECEBER A ESTATISTICA DE TODAS AS INSTANCIAS, USE ESTE */

#define ITERACAO 100
int i, pop, melhor_resultado, frequencia_melhor;
long int media;
void preenche();
void zera();
void escreve(char *arquivo, Lista_Ponto lista, float tempo);

int main(int argc, char **argv) {
    if (argc == 2) {
        srand((unsigned)time(NULL));
        
        Lista_Ponto lista_ponto;
        char string[1000];
        
        inicia_arquivo(argv[1]);

        clock_t Ticks[2];
        
        sprintf(string, "MELHOR_RESULTADO / POPULAÇAO_COBERTA(%%) / FREQUENCIA(%%) / MEDIA_RESULTADO / TEMPO GASTO\n");
        escreve_arquivo(argv[1], string);
        
        //SA (324) - FACILIDADE(1 a 5) - RAIO (800)
        printf("SA - TAMANHO 324 - FACILIDADE 1 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 1 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset/SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset/demand-SJC324.dat");
        lista_ponto->facilidade = 1; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 324 - FACILIDADE 2 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 2 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 2; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 324 - FACILIDADE 3 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 3 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 3; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 324 - FACILIDADE 4 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 4 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 4; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 324 - FACILIDADE 5 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 5 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 5; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        //SA (324) - FACILIDADE(1 a 3) - RAIO (1200)
        printf("SA - TAMANHO 324 - FACILIDADE 1 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 1 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 1; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 324 - FACILIDADE 2 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 2 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 2; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 324 - FACILIDADE 3 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 3 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 3; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 324 - FACILIDADE 4 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 4 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 4; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 324 - FACILIDADE 5 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 5 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 5; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        //SA (324) - FACILIDADE(1 a 2) - RAIO (1600)
        printf("SA - TAMANHO 324 - FACILIDADE 1 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 1 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 1; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 324 - FACILIDADE 2 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 2 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 2; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 324 - FACILIDADE 3 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 3 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 3; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 324 - FACILIDADE 4 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 4 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 4; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 324 - FACILIDADE 5 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 324 - FACILIDADE 5 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC324.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC324.dat");
        lista_ponto->facilidade = 5; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
       
        //SA (500) - FACILIDADE(1 a 8) - RAIO (800)
        printf("SA - TAMANHO 500 - FACILIDADE 1 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 1 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 1; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 2 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 2 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 2; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 3 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 3 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 3; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 4 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 4 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 4; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 5 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 5 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 5; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        //SA (500) - FACILIDADE(1 a 4) - RAIO (1200)
        printf("SA - TAMANHO 500 - FACILIDADE 1 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 1 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 1; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 2 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 2 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 2; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 3 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 3 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 3; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 4 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 4 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 4; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 500 - FACILIDADE 5 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 5 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 5; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        //SA (500) - FACILIDADE(1 a 3) - RAIO (1600)
        printf("SA - TAMANHO 500 - FACILIDADE 1 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 1 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 1; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 2 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 2 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 2; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 500 - FACILIDADE 3 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 3 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 3; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 500 - FACILIDADE 4 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 4 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 4; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 500 - FACILIDADE 5 - RAIO 1600\n");
        sprintf(string, "SA - TAMANHO 500 - FACILIDADE 5 - RAIO 1600\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC500.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC500.dat");
        lista_ponto->facilidade = 5; lista_ponto->raio = 1600; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        

        //SA (324) - FACILIDADE(1 a 5) - RAIO (800)
        printf("SA - TAMANHO 402 - FACILIDADE 1 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 1 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 1; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 402 - FACILIDADE 2 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 2 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 2; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 402 - FACILIDADE 3 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 3 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 3; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 402 - FACILIDADE 4 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 4 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 4; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 402 - FACILIDADE 5 - RAIO 800\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 5 - RAIO 800\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 5; lista_ponto->raio = 800; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        //SA (324) - FACILIDADE(1 a 3) - RAIO (1200)
        printf("SA - TAMANHO 402 - FACILIDADE 1 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 1 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 1; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 402 - FACILIDADE 2 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 2 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 2; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
        
        printf("SA - TAMANHO 402 - FACILIDADE 3 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 3 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 3; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 402 - FACILIDADE 4 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 4 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 4; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);

        printf("SA - TAMANHO 402 - FACILIDADE 5 - RAIO 1200\n");
        sprintf(string, "SA - TAMANHO 402 - FACILIDADE 5 - RAIO 1200\n"); escreve_arquivo(argv[1], string);
        lista_ponto = le_arquivo_ponto("Dataset\\SJC402.dat");
        lista_ponto = le_arquivo_demanda(lista_ponto, "Dataset\\demand-SJC402.dat");
        lista_ponto->facilidade = 5; lista_ponto->raio = 1200; zera();
        Ticks[0] = clock();
        for (i = 0; i < ITERACAO; i++) {
            pop = sa(lista_ponto, argv[1]);
            preenche();
        }
        Ticks[1] = clock();
        escreve(argv[1], lista_ponto, (float)(Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC);
    }
    else {
        printf("ERRO - PARAMETRO");
    }
    return(0);
}

void preenche() {
    if (pop > melhor_resultado) {
        melhor_resultado = pop;
        frequencia_melhor = 1;
    }
    else if (pop == melhor_resultado) {
        frequencia_melhor++;
    }
    media += pop;
    return;
}

void zera() {
    melhor_resultado = 0;
    frequencia_melhor = 0;
    media = 0;
    return;
}

void escreve(char *arquivo, Lista_Ponto lista, float tempo) {
    char string[1000];
    sprintf(string, "%d %.2f %.2f %ld %.2f\n", melhor_resultado, ((melhor_resultado / (float) lista->populacao) * 100), (((float) frequencia_melhor / ITERACAO) * 100), (media / ITERACAO), tempo);
    escreve_arquivo(arquivo, string);
    destroi_lista_ponto(lista);
}
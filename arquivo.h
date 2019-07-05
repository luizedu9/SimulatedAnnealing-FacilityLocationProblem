#ifndef ARQUIVO_H
#define ARQUIVO_H

Lista_Ponto le_arquivo_ponto(char *arquivo);
Lista_Ponto le_arquivo_demanda(Lista_Ponto lista_ponto, char *arquivo);
void inicia_arquivo(char *arquivo);
void escreve_arquivo(char *arquivo, char *string);

#endif /* ARQUIVO_H */
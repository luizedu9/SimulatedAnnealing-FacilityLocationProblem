all:
	gcc -o lista_ponto.o -c lista_ponto.c
	gcc -o arquivo.o -c arquivo.c
	gcc -o sa.o -c sa.c
	gcc -o  main lista_ponto.o arquivo.o sa.o main.c -lm

run:
	./main
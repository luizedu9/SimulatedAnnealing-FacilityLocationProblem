# SimulatedAnnealing-FacilityLocationProblem
a
Instituto Federal de Educação, Ciência e Tecnologia de Minas Gerais, IFMG - Campus Formiga

Ciência da Computação

Simulated Annealing para resolução do Problema de Localização de Facilidades para a disciplina de Métodos Heuristicos 

Autor: Luiz Eduardo Pereira.

# Objetivo:

O Problema de Localização de Facilidades consiste em localizar um ou mais objetos, chamados facilidades. A facilidade interage com objetos vizinhos que possuem uma localização fixa.

Encontrar uma solução para o problema, é encontrar o melhor lugar para a implantação de uma facilidade, tendo como objetivo encontrar o local onde o beneficio será máximo, ou onde o custo será mínimo.

Decisões são tomadas sobre onde localizar facilidades (centros), considerando os outros centros como clientes que devem ser servidos, de forma a otimizar um dado critério. O problema dá origem a vários outros problemas, como o “Problema de Localização de Máxima Cobertura (PLMC)” e o “Problema das p-medianas Capacitado (PPMC)”. Este trabalho abordará apenas o PLMC.

O Problema de Localização de Máxima Cobertura consiste em escolher locais para instalar facilidades de forma que o maior número de clientes (pontos de demanda) sejam cobertos, e saber que cliente será atendido por qual facilidade.

Chamamos a distância do ponto de demanda até a facilidade de distância crítica de serviço (S). S é a distancia máxima que um ponto de demanda pode estar da facilidade para que consiga ser coberta.

O problema resolvido por este trabalho consiste em, dado um conjunto de antenas (p) e o seu raio de cobertura (S), encontrar os pontos para a implantação das facilidades, de modo que maximize a quantidade de pontos de demanda cobertos pelas antenas.

Cada ponto de demanda representa uma quadra de bairros da região central de São José dos Campos – SP e são representados por uma coordenada cartesiana. A demanda de cada ponto baseia-se no número de imóveis em cada quadra. As antenas são alocadas nos mesmos espaços dos pontos de demanda.

# Dataset utilizado:

Foi utilizado o dataset disponibilizado pelo Projeto ARSIG2. Este dataset é uma instância real da cidade São José dos Campos;

Cada arquivo possui coordenadas de quadras da região central da cidade, e cada quadra possui demanda referente a quantidade de imóveis.

As instâncias possuem 324, 402, 500, 708 e 818 pontos;

Disponível em: http://www.lac.inpe.br/~lorena/instancias.html

# Execução:

make all

./main resultado.txt

O programa executará todas as instancias, variando o tamanho da instancia, quantidade de antenas e raio das antenas.

O arquivo resultado.txt possui as coordenadas onde as antenas deverão ser posicionadas e a população total coberta por elas.

# Trabalho de Aquecimento - Jogo Da Vida - Algoritmo e Estrutura de Dados

## Introdução

O Jogo da Vida é um autômato celular que evolui de acordo com regras simples, mas
gera padrões complexos, este programa é uma reconstrução do jogo usando a linguagem C++.
Ele é representado por uma matriz 2D de células, cada uma podendo estar viva, sendo
representada por [1] ou morta, sendo representada por [0].

## Objetivo

O objetivo deste trabalho é revisar os conceitos de manipulação de matrizes, controle
de fluxo e lógica de jogo. Para concretizar isto, foi necessário a criação de programa
que se adequasse a diferentes matrizes e que formulasse resoluções a partir das seguintes regras:

* Uma célula viva com menos de dois vizinhos morre (solidão);
* Uma célula viva com mais de três vizinhos morre (superpopulação);
* Uma célula viva com dois ou três vivos sobrevive;
* Uma célula morta com exatamente três vizinhos vivos se torna viva (reprodução).

## Sobre o Projeto

### Arquivos

* main.cpp
* LifeGame.cpp (classe onde está o jogo)
* LifeGame.hpp
* File.cpp (classe para mexer com arquivos)
* File.hpp
* input.mps (arquivo de entrada com a matriz)
* geracoes.mps (arquivo de saida onde se encontra o resultado)

### Problemas Encontrados

Não houve barreiras durante a criação do programa que pudessem impedi-lo de ser perpetuado, 
foi possivel pensar na lógica e efetuá-la de maneira tranquila. Entretanto, houve apenas uma 
dificuldade quanto a manipulação de arquivos, o que foi facilmente contornado com a ajuda do professor.

### Testes Efetuados 
Entrada:
![Formatação](https://github.com/ByBrun0/Jogo-Da-Vida/assets/143546997/cbedeeda-5cde-44f5-bef4-15d40587c2f2)


Saída:
![Resultado](https://github.com/ByBrun0/Jogo-Da-Vida/assets/143546997/b348bc27-4b8f-4189-a419-b357aee8012b)



## Instruções Do Projeto

Insira no arquivo "input.mps" a matriz, a qual deve contar com o tamanho, o qual
deve ter um valor minimo de 5, em uma linha e com os números '0' e '1' separados por espaço e
divididos de uma forma em que haja uma fração de 2 para 1 na quantidade dos '0' e '1', sendo que 
o '1' apareça com menos frequência. Siga o exemplo de formatação sugerido:

![Formatação](https://github.com/ByBrun0/Jogo-Da-Vida/assets/143546997/0acb8e11-7147-46d4-8bdb-6906b7b80e5b)



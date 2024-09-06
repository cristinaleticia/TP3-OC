// selection_sort_blocks.h

#ifndef SELECTION_SORT_BLOCKS_H
#define SELECTION_SORT_BLOCKS_H
#include <stdio.h>
#include <stdlib.h>
// Definindo o tipo de dado utilizado no vetor (int neste caso)
typedef int type_t;

// Funcao que troca os valores apontados pelos ponteiros x e y (evita trocas desnecessárias)
void swap(type_t *x, type_t *y);

// Funcao que ordena um bloco do vetor utilizando o algoritmo de selecao
void selection_sort_bloco(type_t vetor[], size_t start, size_t end);

// Função principal que ordena o vetor, divide em blocos menores que serao ordenados por selection_sort_bloco
// e depois junta eles ordenando o vetor completo
void selection_externo(type_t vetor[], size_t length);

#endif // SELECTION_SORT_BLOCKS_H

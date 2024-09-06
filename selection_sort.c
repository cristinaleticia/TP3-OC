#include "selection_sort.h"

static void swap(type_t *x, type_t *y) {
    type_t tmp = *x;
    *x = *y;
    *y = tmp;
}

// Ordena um vetor utilizando o Selection Sort
void selection_sort(type_t vetor[], size_t length) {
    // Ordena o vetor de entrada
    for (size_t i = 0; i < (length - 1); i++) {
        size_t menor = i;

        // Encontra o menor elemento no subvetor não ordenado
        for (size_t j = i + 1; j < length; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        // Coloca o menor elemento em sua posição final
        swap(&vetor[i], &vetor[menor]);
    } 
}

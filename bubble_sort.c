#include "bubble_sort.h"
// Algoritmo bubble_sort, do site http://devfuria.com.br/logica-de-programacao/exemplos-na-linguagem-c-do-algoritmo-bubble-sort/


void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        //printf("\n[%d] ", k);

        for (j = 0; j < n - 1; j++) {
            //printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}


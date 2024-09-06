#include "radix_sort.h"
// Algoritmo radix_sort, do site https://www.geeksforgeeks.org/radix-sort/

// Função auxiliar para obter o valor máximo em vetor
int getMax(int vetor[], int n) {
    int mx = vetor[0];
    for (int i = 1; i < n; i++)
        if (vetor[i] > mx)
            mx = vetor[i];
    return mx;
}

// Função para fazer o countSort de vetor de acordo com o dígito representado por exp
void countSort(int vetor[], int n, int exp) {
    int output[n]; // Vetor de saída
    int count[10] = {0}; // Inicializa o vetor de contagem com 0

    // Armazena a contagem das ocorrências em count[]
    for (int i = 0; i < n; i++)
        count[(vetor[i] / exp) % 10]++;

    // Modifica count[i] para que count[i] agora contenha a posição real deste dígito em output
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constrói o vetor de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(vetor[i] / exp) % 10] - 1] = vetor[i];
        count[(vetor[i] / exp) % 10]--;
    }

    // Copia o array de saída para vetor, para que vetor agora contenha os números 
    // ordenados de acordo com o dígito atual
    for (int i = 0; i < n; i++)
        vetor[i] = output[i];
}

// Função principal para ordenar vetor de tamanho n usando o Radix Sort
void radixSort(int vetor[], int n) {
  
    // Encontra o número máximo para saber 
    // o número de dígitos
    int m = getMax(vetor, n); 

    // Faz o counting sort para cada dígito
    // exp é 10^i onde i é o número do dígito atual
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(vetor, n, exp);
}

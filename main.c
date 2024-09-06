#include "bubble_sort.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "selection_sort.h"
#include "selection_melhorado.h"
// Função auxiliar para imprimir um vetor
void printArray(int vetor[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

int main(void){
  int tamanho = 20;
  int vetor[tamanho];
  srand(time(NULL));
  for (int i = 0; i < tamanho; i++){
    vetor[i] = (rand() % 200); // gerando uma posicao aleatoria que vai de 1 ate 200
  }
  printArray(vetor, tamanho);
  selection_externo(vetor, tamanho);
  printArray(vetor, tamanho);
}

   
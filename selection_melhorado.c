#include "selection_melhorado.h"
typedef int type_t;

#define tamanho_bloco 32 // Um tamanho bom estimado para a cache, considerando que vamos ocupar  uma parte pequena dela mesmo 
// carregando todos os dados e, ainda assim, conseguimos juntar eles facilidade

//Para evitar alterar a memoriaa de maneira desnecessaria, vericamos se os dados sao difrentes (nao trocamos dados iguais)
void swap(type_t *x, type_t *y) {
    if (x != y) {
        type_t tmp = *x;
        *x = *y;
        *y = tmp;
    }
}

// Agora utilizamos uma estrategia parecida com dividir para conquistar, onde ordenamos blocos menores e depois juntamos todos eles
// assim o algoritmo trabalha com conjunto de dados menores, que podem ser carregadas inteiramente na cache
// reduzindo a necessidade de acessar a memoria principal, que é muito mais lenta
// Dessa maneira tambem reduzimos o numero de mis pois os blocos nao estao dispersos na memoria como no tradicional
 
void selection_sort_bloco(type_t vetor[], size_t start, size_t end) {
    //Metodo tradicional de selecao
    for (size_t i = start; i < end - 1; i++) {
        size_t menor = i;
        for (size_t j = i + 1; j < end; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        swap(&vetor[i], &vetor[menor]);
    }
}

// Funcao principal que divide o vetor em blocos, chama a ordenacao dos blocos e ordena todo o vetor no final
void selection_externo(type_t vetor[], size_t length) {
    size_t i;

    // Processa cada bloco separadamente
    for (i = 0; i + tamanho_bloco <= length; i += tamanho_bloco) {
        selection_sort_bloco(vetor, i, i + tamanho_bloco);
    }

    // Processa o bloco final que pode ter tamanho menor que tamanho_bloco, garantindo que todos os blocos estejam ordenados
    if (i < length) {
        selection_sort_bloco(vetor, i, length);
    }

    // Ordena o vetor inteiro apos os blocos estarem organizados internamente
    for (size_t i = 0; i < (length - 1); i++) {
        size_t menor = i;
        for (size_t j = i + 1; j < length; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        swap(&vetor[i], &vetor[menor]);
    }
}
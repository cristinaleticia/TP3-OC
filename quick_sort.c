#include "quick_sort.h"
// ALGORITMO QUICKSORT - https://gist.github.com/marcoscastro/1dd65900cc7b188e1ab9

// função que realiza a troca entre dois elementos
void troca(int vetor[], int i, int j){
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vetor[], int inicio, int fim){
	int pivo, pivo_indice, i;
	
	pivo = vetor[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vetor[i] <= pivo)
		{
			// realiza a troca
			troca(vetor, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vetor, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vetor[], int inicio, int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vetor, pivo_indice, fim);
	// chama a particiona
	return particiona(vetor, inicio, fim);
}

void quick_sort(int vetor[], int inicio, int fim)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vetor, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vetor, inicio, pivo_indice - 1);
		quick_sort(vetor, pivo_indice + 1, fim);
	}
}


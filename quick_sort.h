#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time

void troca(int vetor[], int i, int j);

int particiona(int vetor[], int inicio, int fim);

int particiona_random(int vetor[], int inicio, int fim);

void quick_sort(int vetor[], int inicio, int fim);

#endif // QUICK_SORT_H

#ifndef RADIX_SORT_H
#define RADIX_SORT_H


#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time

int getMax(int vetor[], int n);

void countSort(int vetor[], int n, int exp);

void radixSort(int vetor[], int n);

#endif // RADIX_SORT_H

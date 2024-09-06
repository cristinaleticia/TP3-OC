
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time

typedef int type_t;

static void swap(type_t *x, type_t *y);

void selection_sort(type_t vetor[], size_t length);

#endif // SELECTION_SORT_H

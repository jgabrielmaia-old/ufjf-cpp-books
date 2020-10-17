#include "sorters.h"

#include <string.h>

void insertionsort(Book **to_sort, int size, int swap_count, int compare_count) {
    int i, j;
    Book *pivot;

    for (j = 1; j < size; j++)
    {
        compare_count++;
        pivot = to_sort[j];
        i = j - 1;

        while (i >= 0 && (strcmp(to_sort[i]->title, pivot->title) > 0))
        {
            compare_count++;
            to_sort[i + 1] = to_sort[i];
            swap_count++;
            i--;
        }
        compare_count++;

        to_sort[i + 1] = pivot;
        swap_count++;
    }
    compare_count++;
}
#include "sorters.h"

#include <string.h>

void insertionsort(Book **to_sort, int size, int copy_count, int compare_count)
{
    int i, j;
    Book *pivot;

    for (j = 1; j < size; j++)
    {
        pivot = to_sort[j];
        i = j - 1;

        while (i >= 0 && (strcmp(to_sort[i]->title, pivot->title) > 0))
        {
            compare_count++;
            to_sort[i + 1] = to_sort[i];
            copy_count++;
            i--;
        }

        to_sort[i + 1] = pivot;
        copy_count++;
    }
}
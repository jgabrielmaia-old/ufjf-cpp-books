#include "sorters.h"
#include "quicksort.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

void quicksort(Book **to_sort, int size, int swap_count, int compare_count)
{
    sort(to_sort, 0, size - 1, swap_count, compare_count);
}

void sort(Book **to_sort, int low, int high, int swap_count, int compare_count)
{
    if (low < high)
    {
        int pi = partition(to_sort, low, high, swap_count, compare_count);

        sort(to_sort, low, pi - 1, swap_count, compare_count);
        sort(to_sort, pi + 1, high, swap_count, compare_count);
    }
}

int partition(Book **to_sort, int low, int high, int swap_count, int compare_count)
{
    Book *pivot = to_sort[high];
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        int compare = strcmp(to_sort[j]->title, pivot->title);
        if (compare < 0 || compare == 0)
        {
            i++; // increment index of smaller element
            swap(to_sort[i], to_sort[j], swap_count);
        }
    }
    swap(to_sort[i + 1], to_sort[high], swap_count);
    return (i + 1);
}

void swap(Book *a, Book *b, int swap_count)
{
    Book t = *a;
    *a = *b;
    *b = t;
}
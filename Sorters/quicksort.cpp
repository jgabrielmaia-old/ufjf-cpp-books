#include "sorters.h"
#include "quicksort.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void quicksort(Book **to_sort, int size, int swap_count, int compare_count)
{

    sort(to_sort, 0, size - 1);
    printArray(to_sort, size);
}

void sort(Book **to_sort, int low, int high)
{
    if (low < high)
    {
        int pi = partition(to_sort, low, high);

        sort(to_sort, low, pi - 1);
        sort(to_sort, pi + 1, high);
    }
}

int partition(Book **to_sort, int low, int high)
{
    Book *pivot = to_sort[high]; // pivot
    int i = (low - 1);           // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (to_sort[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(to_sort[i], to_sort[j]);
        }
    }
    swap(to_sort[i + 1], to_sort[high]);
    return (i + 1);
}

void swap(Book *a, Book *b)
{
    Book *t = a;
    a = b;
    b = t;
}

void printArray(Book **to_sort, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << to_sort[i] << " ";
    cout << endl;
}
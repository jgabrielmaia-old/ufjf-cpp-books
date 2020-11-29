#include "sorters.h"
#include "quicksort.h"
#include <string.h>

void quicksort(Book **to_sort, int size, int copy_count, int compare_count)
{
    sort(to_sort, 0, size - 1, copy_count, compare_count);
}

void quicksort_a(HashedAuthor **to_sort, int size)
{
    sort_a(to_sort, 0, size - 1);
}

void sort_a(HashedAuthor **to_sort, int low, int high)
{
    if (low < high)
    {
        int pi = partition_a(to_sort, low, high);

        sort_a(to_sort, low, pi - 1);
        sort_a(to_sort, pi + 1, high);
    }
}


void sort(Book **to_sort, int low, int high, int copy_count, int compare_count)
{
    if (low < high)
    {
        int pi = partition(to_sort, low, high, copy_count, compare_count);

        sort(to_sort, low, pi - 1, copy_count, compare_count);
        sort(to_sort, pi + 1, high, copy_count, compare_count);
    }
}

int partition(Book **to_sort, int low, int high, int copy_count, int compare_count)
{
    Book *pivot = to_sort[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        int compare = strcmp(to_sort[j]->title, pivot->title);
        if (compare < 0 || compare == 0)
        {
            compare_count++;
            i++;
            swap(to_sort[i], to_sort[j], copy_count);
        }
    }
    swap(to_sort[i + 1], to_sort[high], copy_count);
    return (i + 1);
}

int partition_a(HashedAuthor **to_sort, int low, int high)
{
    HashedAuthor *pivot = to_sort[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (to_sort[j]->hit_count >= pivot->hit_count)
        {
            i++;
            swap_a(to_sort[i], to_sort[j]);
        }
    }
    swap_a(to_sort[i + 1], to_sort[high]);
    return (i + 1);
}

void swap(Book *a, Book *b, int copy_count)
{
    Book t = *a;
    *a = *b;
    *b = t;
    copy_count++;
}

void swap_a(HashedAuthor *a, HashedAuthor *b)
{
    HashedAuthor t = *a;
    *a = *b;
    *b = t;
}
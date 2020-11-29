#ifndef SORTERS
#define SORTERS

#include "../Model/book.h"
#include "../Model/hashed_author.h"

void insertionsort(Book **to_sort, int size, int copy_count, int compare_count);
void quicksort(Book **to_sort, int size, int copy_count, int compare_count);
void quicksort_a(HashedAuthor **to_sort, int size);
#endif
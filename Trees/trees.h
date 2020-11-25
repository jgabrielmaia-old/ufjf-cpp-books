#ifndef TREES
#define TREES

#include "../Model/book.h"

void insertRBTree(Book **to_sort, int size, int copy_count, int compare_count);
void searchRBTree(Book **to_sort, int size, int copy_count, int compare_count);

#endif
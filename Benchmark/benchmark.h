#ifndef BENCHMARK
#define BENCHMARK

#include "../Model/book.h"
#include "../GUI/gui.h"
#include "../DAL/random_reader.h"
#include "../Sorters/sorters.h"

void benchmark(Book **books);
void test(Book **books, int batch_size);
Book **sample(Book **books, int batch_size);
void run(string name, void (*sorter)(Book **to_sort, int size, int swap_count, int compare_count), Book **to_sort, int size);
void timer(void (*sorter)(Book **to_sort, int size, int swap_count, int compare_count), Book **to_sort, int size, int swap_count, int compare_count);

#endif
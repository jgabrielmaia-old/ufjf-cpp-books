#ifndef BENCHMARK
#define BENCHMARK

#include "../Model/book.h"
#include "../GUI/gui.h"
#include "../DAL/random_reader.h"
#include "../Sorters/sorters.h"

string benchmark(Book **books);
string test(Book **books, int batch_size);
Book **sample(Book **books, int batch_size);
string run(string name, void (*sorter)(Book **to_sort, int size, int copy_count, int compare_count), Book **to_sort, int size);
double timer(void (*sorter)(Book **to_sort, int size, int copy_count, int compare_count), Book **to_sort, int size, int copy_count, int compare_count);

#endif
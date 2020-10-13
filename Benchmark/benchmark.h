#ifndef BENCHMARK
#define BENCHMARK

#include "../Model/book.h"
#include "../GUI/gui.h"
#include "../DAL/random_reader.h"

Book **sample(Book **books, int batch_size);
void test(Book **books, int batch_size);

// número de comparações de chaves
// número de cópias de registros
// tempo total gasto na ordenação
// impressos ao final de cada ordenação

#endif
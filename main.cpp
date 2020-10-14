#include "Model/book.h"
#include "GUI/gui.h"
#include "DAL/csv_reader.h"
#include "Benchmark/benchmark.h"

#include <stdlib.h>

Book **sample(Book **books, int batch_size);

int main(int argc, char const *argv[])
{
    int library_size = 1000;
    Book **books = (Book **)malloc(library_size * sizeof(Book *));
    FILE *stream = fopen("CSV/dataset_simp_sem_descricao.csv", "r");

    trace(INFO, "Lendo livros de arquivo...");
    books = read_book_from_csv(stream, library_size);
    trace_i(INFO, "Livros alocados em memoria: ", library_size);

    delete stream;

    benchmark(books);

    return 0;
}
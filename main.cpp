#include "Model/book.h"
#include "GUI/gui.h"
#include "DAL/csv_reader.h"
#include "DAL/output_writer.h"
#include "Benchmark/benchmark.h"

#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int library_size = 1'000'000;
    Book **books = (Book **)malloc(library_size * sizeof(Book *));
    FILE *stream = fopen("CSV/dataset_simp_sem_descricao.csv", "r");

    trace(INFO, "Lendo "+ to_string(library_size) + " livros de arquivo...");
    books = read_book_from_csv(stream, library_size);
    trace_i(INFO, "Livros alocados em memoria: ", library_size);

    delete stream;

    string result = benchmark(books);

    write_to_file("saida.txt", result);
    return 0;
}
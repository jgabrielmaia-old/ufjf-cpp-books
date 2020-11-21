#include "Model/book.h"
#include "Model/author.h"
#include "Model/mapping.h"
#include "GUI/gui.h"
#include "DAL/csv_reader.h"
#include "DAL/input_reader.h"
#include "DAL/output_writer.h"
#include "Benchmark/benchmark.h"

#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int library_size = 1'000;
    Book **books = (Book **)malloc(library_size * sizeof(Book *));
    FILE *stream = fopen("CSV/dataset_simp_sem_descricao.csv", "r");

    trace(INFO, "Lendo " + to_string(library_size) + " livros de arquivo...");
    books = read_book_from_csv(stream, library_size);
    trace_i(INFO, "Livros alocados em memoria: ", library_size);

    Author **authors = books_to_authors(books, library_size);

    for (size_t i = 0; i < library_size; i++)
    {
        print_author(authors[i]);
    }

    delete stream;

    // stream = fopen("entrada.txt", "r");
    // int test_size = get_test_size(stream);
    // trace_i(INFO, "Quantidade de tamanhos de amostra: ", test_size);
    // int *tests = read_input(stream, test_size);
    // delete stream;

    // string result = benchmark(books, tests, test_size);

    // write_to_file("saida.txt", result);
    return 0;
}
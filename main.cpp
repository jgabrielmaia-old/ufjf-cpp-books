#include "Model/book.h"
#include "Model/author.h"
#include "GUI/gui.h"
#include "DAL/csv_reader.h"
#include "DAL/input_reader.h"
#include "DAL/output_writer.h"
#include "Benchmark/benchmark.h"
#include "Hash/hash.h"
#include "Benchmark/benchmarkTrees.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // int library_size = 1'000'000;
    // Book **books = (Book **)malloc(library_size * sizeof(Book *));
    // FILE *stream = fopen("CSV/dataset_simp_sem_descricao.csv", "r");

    // trace(INFO, "Lendo " + to_string(library_size) + " livros de arquivo...");
    // books = read_book_from_csv(stream, library_size);
    // trace_i(INFO, "Livros alocados em memoria: ", library_size);
    // delete stream;

    int authors_list_size = 50'464;
    Author **authors = (Author **) malloc(authors_list_size * sizeof(Author *));
    FILE *author_stream = fopen("CSV/authors.csv", "r");

    trace(INFO, "Lendo " + to_string(authors_list_size) + " livros de arquivo...");
    authors = read_authors_from_csv(author_stream, authors_list_size);
    trace_i(INFO, "Autores alocados em memoria: ", authors_list_size);

    delete author_stream;

    for (size_t i = 0; i < authors_list_size; i++)
    {
        print_author(authors[i]);
    }

    // HashTable<Author *> *authors_hash_table = authors_to_hash_authors(authors, authors_list_size);

    return 0;
}
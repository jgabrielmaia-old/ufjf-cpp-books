#include "Model/book.h"
#include "Model/author.h"
#include "GUI/gui.h"
#include "DAL/csv_reader.h"
#include "DAL/input_reader.h"
#include "DAL/output_writer.h"
#include "Benchmark/benchmark.h"
#include "Hash/hash.h"
#include "Model/mapping.h"
#include "Benchmark/benchmarkTrees.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int authors_list_size = 50'464;
    Author **authors = (Author **) malloc(authors_list_size * sizeof(Author *));
    FILE *author_stream = fopen("CSV/authors.csv", "r");

    trace(INFO, "Lendo " + to_string(authors_list_size) + " livros de arquivo...");
    authors = read_authors_from_csv(author_stream, authors_list_size);
    trace_i(INFO, "Autores alocados em memoria: ", authors_list_size);

    fclose(author_stream);

    HashTable *authors_hash_table = new HashTable(authors_list_size);

    entities_to_hash(authors, authors_hash_table, authors_list_size);
    authors_hash_table->print_hash_table();

    return 0;
}
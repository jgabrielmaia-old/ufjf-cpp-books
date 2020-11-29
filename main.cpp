#include "Model/book.h"
#include "Model/author.h"
#include "GUI/gui.h"
#include "DAL/csv_reader.h"
#include "DAL/input_reader.h"
#include "DAL/output_writer.h"
#include "Benchmark/benchmark.h"
#include "Hash/hash.h"
#include "DAL/mapping.h"
#include "Benchmark/benchmarkTrees.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *input_stream = fopen("entrada.txt", "r");
    int *inputs = read_input(input_stream, 1);

    int library_size = 200000;
    Book **books = (Book **)malloc(library_size * sizeof(Book *));
    FILE *stream = fopen("CSV/dataset_simp_sem_descricao.csv", "r");

    trace(INFO, "Lendo " + to_string(library_size) + " livros de arquivo...");
    books = read_book_from_csv(stream, library_size);
    trace_i(INFO, "Livros alocados em memoria: ", library_size);
    fclose(stream);

    int authors_list_size = 50464;
    Author **authors = (Author **)malloc(authors_list_size * sizeof(Author *));
    FILE *author_stream = fopen("CSV/authors.csv", "r");

    trace(INFO, "Lendo " + to_string(authors_list_size) + " livros de arquivo...");
    authors = read_authors_from_csv(author_stream, authors_list_size);
    trace_i(INFO, "Autores alocados em memoria: ", authors_list_size);

    fclose(author_stream);

    HashTable *authors_hash_table = new HashTable(1000);

    trace(INFO, "Mapeando autores para a tabela hash...");
    entities_to_hash(authors, authors_hash_table, authors_list_size);
    trace(INFO, "Tabela hash de autores populada.");

    trace(INFO, "Pesquisar autores nos livros...");
    authors_hash_table->search_authors_in_books(books, library_size);
    trace(INFO, "Autores pesquisados");

    trace(INFO, "Populando lista de frequencia...");
    HashedAuthor **frequency_list = hashed_authors_to_list(authors_hash_table, authors_list_size);
    trace(INFO, "Lista de frequencia populada.");

    trace(INFO, "Ordenando lista de frequencia...");
    quicksort_a(frequency_list, authors_list_size);
    trace(INFO, "Lista de frequencia ordenada.");

    trace_i(INFO, "Consolidando resultados. Tamanho da lista de autores: ", inputs[0]);
    string most_frequent_authors = hashed_authors_consolidate_in_string(frequency_list, inputs[0]);
    trace(INFO, "Resultados consolidados.");

    trace(INFO, "Gerando saida...");
    write_to_file("most_frequent_authors.txt", most_frequent_authors);
    trace(INFO, "Saida gerada.");

    return 0;
}
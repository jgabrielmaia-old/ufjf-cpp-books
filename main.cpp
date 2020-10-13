#include "Model/book.h"
#include "ConsoleGUI/gui.h"
#include "DAL/csv_reader.h"
#include "DAL/random_reader.h"
#include <stdlib.h>

Book **sample(Book **books, int batch_size);

int main(int argc, char const *argv[])
{
    int library_size = 1'000;
    Book **books = (Book **)malloc(library_size * sizeof(Book *));
    FILE *stream = fopen("CSV/dataset_simp_sem_descricao.csv", "r");

    trace(INFO, "Lendo livros de arquivo...");
    books = read_book_from_csv(stream, library_size);
    trace(INFO, "Livros alocados em memoria: ", library_size);

    delete stream;

    int batch_size = 10;
    Book **random_book_set = (Book **)malloc(batch_size * sizeof(Book *));
    random_book_set = sample(books, batch_size);

    return 0;
}

Book **sample(Book **books, int batch_size)
{
    Book **random_book_set = (Book **)malloc(batch_size * sizeof(Book *));
    trace(INFO, "Gerando conjunto aleatorio de livros...");

    random_book_set = get_random_books(books, batch_size);

    cout << endl;
    for (size_t i = 0; i < batch_size; i++)
    {

        print_book(random_book_set[i]);
    }
    cout << endl;

    trace(INFO, "Conjunto aleatorio de livros gerado. Tamanho: ", batch_size);

    return random_book_set;
}
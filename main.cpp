#include "Model/book.h"
#include "ConsoleGUI/gui.h"
#include "DAL/csv_reader.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int library_size = 1'000;

    Book **books = (Book**) malloc(library_size * sizeof(Book*));

    FILE *stream = fopen("CSV/dataset_simp_sem_descricao.csv", "r");

    read_book_from_csv(books, stream, library_size);

    delete stream;

    for (size_t i = 0; i < library_size; i++)
    {
        print_book_q(books[i]);
    }

    return 0;
}

#include "benchmark.h"

#include <stdlib.h>
#include <time.h>

Book **sample(Book **books, int batch_size)
{
    Book **random_book_set = (Book **)malloc(batch_size * sizeof(Book *));
    trace(INFO, "Gerando conjunto aleatorio de livros...");

    random_book_set = get_random_books(books, batch_size);

    cout << endl;
    for (size_t i = 0; i < batch_size; i++)
    {
        print_book_q(random_book_set[i]);
    }
    cout << endl;

    trace(INFO, "Conjunto aleatorio de livros gerado. Tamanho: ", batch_size);

    return random_book_set;
}

void test(Book **books, int batch_size)
{
    Book **test_set = (Book **)malloc(batch_size * sizeof(Book *));

    srand(time(0));
    for (size_t i = 0; i < 5; i++)
    {
        test_set = sample(books, batch_size);
    }
}
// número de comparações de chaves
// número de cópias de registros
// tempo total gasto na ordenação
// impressos ao final de cada ordenação

// testes: N = 1000, 5000, 10000, 50000 e 100000
#include "benchmark.h"

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string>

void benchmark(Book **books)
{
    test(books, 10);
    // test(books, 5'000);
    // test(books, 10'000);
    // test(books, 50'000);
    // test(books, 100'000);

    trace(INFO, "All tests finished.");
}

void test(Book **books, int batch_size)
{
    srand(time(0));
    for (size_t i = 0; i < 5; i++)
    {
        run("Insertion Sort", insertionsort, sample(books, batch_size), batch_size);
        // run("Quick Sort", quicksort, sample(books, batch_size), batch_size);
    }
}

Book **sample(Book **books, int batch_size)
{
    Book **random_book_set = (Book **)malloc(batch_size * sizeof(Book *));
    trace(INFO, "Gerando conjunto aleatorio de livros...");

    random_book_set = get_random_books(books, batch_size);

    trace_i(INFO, "Conjunto aleatorio de livros gerado. Tamanho: ", batch_size);

    return random_book_set;
}

void run(string name, void (*sorter)(Book **to_sort, int size, int swap_count, int compare_count), Book **to_sort, int size)
{
    trace_s(INFO, "Ordenar livros com algoritmo ", name);
    int swap_count = 0;
    int compare_count = 0;
    timer(sorter, to_sort, size, swap_count, compare_count);
    trace_i(INFO, "Swaps: ", swap_count);
    trace_i(INFO, "Comparações : ", compare_count);
}

void timer(void (*sorter)(Book **to_sort, int size, int swap_count, int compare_count), Book **to_sort, int size, int swap_count, int compare_count)
{
    struct timeval begin, end;
    trace(INFO, "Contador ativado!");
    gettimeofday(&begin, 0);

    sorter(to_sort, size, swap_count, compare_count);

    gettimeofday(&end, 0);
    trace(INFO, "Contador parado!");
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;

    cout<< endl;
    for (size_t i = 0; i < size; i++)
    {
        print_book_t(to_sort[i]);
    }
    cout<< endl;

    trace_d(INFO, "Time measured in seconds: ", elapsed);
}
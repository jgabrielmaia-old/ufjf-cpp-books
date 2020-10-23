#include "benchmark.h"

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string>

string benchmark(Book **books)
{
    string result;
    result+= test(books, 10);
    // test(books, 5'000);
    // test(books, 10'000);
    // test(books, 50'000);
    // test(books, 100'000);

    trace(INFO, "All tests finished.");

    return result;
}

string test(Book **books, int batch_size)
{
    string result;
    srand(time(0));
    result+= "Tamanho da amostra: " + to_string(batch_size) + "\r\n";
    result+= "---------------------------------------------------\r\n";
    for (size_t i = 0; i < 5; i++)
    {
        run("Insertion Sort", insertionsort, sample(books, batch_size), batch_size);
        run("Quick Sort", quicksort, sample(books, batch_size), batch_size);
    }

    return result;
}

Book **sample(Book **books, int batch_size)
{
    Book **random_book_set = (Book **)malloc(batch_size * sizeof(Book *));
    trace(INFO, "Gerando conjunto aleatorio de livros...");

    random_book_set = get_random_books(books, batch_size);

    trace_i(INFO, "Conjunto aleatorio de livros gerado. Tamanho: ", batch_size);

    return random_book_set;
}

string run(string name, void (*sorter)(Book **to_sort, int size, int swap_count, int compare_count), Book **to_sort, int size)
{
    string result;
    trace_s(INFO, "Ordenar livros com algoritmo ", name);
    int swap_count = 0;
    int compare_count = 0;
    double elapsed = timer(sorter, to_sort, size, swap_count, compare_count);
    trace_i(INFO, "Swaps: ", swap_count);
    trace_i(INFO, "Comparações : ", compare_count);

    result+= "Ordenador:" + name + "\r\n";
    result+= "Swaps: " + to_string(swap_count) + "\r\n";
    result+= "Comparações: " + to_string(swap_count) + "\r\n";
    result+= "Tempo: " + to_string(elapsed) + "\r\n";
    result+= "\r\n";

    return result;
}

double timer(void (*sorter)(Book **to_sort, int size, int swap_count, int compare_count), Book **to_sort, int size, int swap_count, int compare_count)
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

    return elapsed;
}
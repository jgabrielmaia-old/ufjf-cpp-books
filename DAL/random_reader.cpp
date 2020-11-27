#include "random_reader.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int MAX_LIMIT = 1'000'000;

Book **get_random_books(Book **books, int batch_size)
{
    Book **random_set = (Book **)malloc(batch_size * sizeof(Book *));

    int *indexes = getRandomNumbers(batch_size);

    for (size_t i = 0; i < batch_size; i++)
    {
        random_set[i] = books[indexes[i]];
    }

    return random_set;
}

int *getRandomNumbers(int count)
{
    int i, *random = new int[count];

    for (i = 0; i < count; i++)
    {
        random[i] = rand() % MAX_LIMIT;
    }

    return random;
}
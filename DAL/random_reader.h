#ifndef RANDOM_READER
#define RANDOM_READER

#include "../Model/book.h"

Book **get_random_books(Book **books, int batch_size);
int *getRandomNumbers(int count);

#endif
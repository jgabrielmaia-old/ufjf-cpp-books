#ifndef CSV_READER
#define CSV_READER

#include "../Model/book.h"
#include <stdio.h>

void read_book_from_csv(Book **arr_books, FILE *stream, int take);
Book *get_fields(char *line);

#endif
#ifndef CSV_READER
#define CSV_READER

#include "../Model/book.h"
#include <stdio.h>

Book **read_book_from_csv(FILE *stream, int take);
Book *get_fields(char *line);

#endif
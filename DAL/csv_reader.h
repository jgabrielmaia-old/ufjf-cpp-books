#ifndef CSV_READER
#define CSV_READER

#include "../Model/book.h"
#include "../Model/author.h"
#include <stdio.h>

Book **read_book_from_csv(FILE *stream, int take);
Book *get_fields(char *line);

Author **read_authors_from_csv(FILE *stream, int take);
Author *get_author_fields(char *line);

#endif
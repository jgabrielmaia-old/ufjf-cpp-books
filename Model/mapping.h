#ifndef MAPPING
#define MAPPING

#include "../DAL/csv_reader.h"
#include "book.h"
#include "author.h"

Author **books_to_authors(Book **books, int size);

#endif
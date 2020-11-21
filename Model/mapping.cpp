#include "mapping.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Author **books_to_authors(Book **books, int library_size)
{

    Author **authors = (Author **)malloc(library_size * sizeof(Author *));

    for (size_t i = 0; i < library_size; i++)
    {
        Author *author = (Author *)malloc(sizeof(Author));

        strcpy(author->id, books[i]->authors);

        authors[i] = author;
    }

    return authors;
}
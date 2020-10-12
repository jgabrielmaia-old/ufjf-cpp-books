#include "csv_reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <iostream>
using namespace std;

void read_book_from_csv(Book **arr_books, FILE *stream, int take)
{
    int m = 0;
    char line[1024];

    while (fgets(line, 1024, stream) && m < take)
    {
        arr_books[m++] = get_fields(line);
    }
}

Book *get_fields(char *line)
{
    Book *book = (Book *)malloc(sizeof(Book));
    int i, field_count = 0, field_pos = 0;

    for (i = 0; i < strlen(line); i++)
    {
        if (line[i] == '\"')
        {
            string field;

            while (line[++i] != '\"')
            {
                field += line[i];
            }

            field_pos++;
            switch (field_pos)
            {
            case 1:
                strcpy(book->authors, field.c_str());
                break;
            case 2:
                strcpy(book->best_sellers_rank, field.c_str());
                break;
            case 3:
                strcpy(book->categories, field.c_str());
                break;
            case 4:
                strcpy(book->edition, field.c_str());
                break;
            case 5:
                strcpy(book->id, field.c_str());
                break;
            case 6:
                strcpy(book->isbn10, field.c_str());
                break;
            case 7:
                strcpy(book->isbn13, field.c_str());
                break;
            case 8:
                strcpy(book->rating_avg, field.c_str());
                break;
            case 9:
                strcpy(book->rating_count, field.c_str());
                break;
            case 10:
                strcpy(book->title, field.c_str());
                break;
            default:
                break;
            }
        }
    }

    return book;
}
#ifndef BOOK
#define BOOK

struct Book
{
    char id[15];
    char authors[50];
    char best_sellers_rank[50];
    char categories[50];
    char edition[50];
    char isbn10[50];
    char isbn13[50];
    char rating_avg[50];
    char rating_count[50];
    char title[500];
};

#endif
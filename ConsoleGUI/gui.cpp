#include "gui.h"

void print_book(Book* b)
{
    cout << "Id: " << b->id << endl;
    cout << "Authors: " << b->authors << endl;
    cout << "Best sellers rank: " << b->best_sellers_rank << endl;
    cout << "Categories: " << b->categories << endl;
    cout << "Edition: " << b->edition << endl;
    cout << "ISBN 10: " << b->isbn10 << endl;
    cout << "ISBN 13: " <<b->isbn13 << endl;
    cout << "Rating Average: " << b->rating_avg << endl;
    cout << "Rating count: " << b->rating_count << endl;
    cout << "Title: " << b->title << endl;
    cout << endl;
}

void print_book_q(Book* b)
{
    cout << b->id << endl;
}
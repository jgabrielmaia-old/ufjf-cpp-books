#include "gui.h"

void print_book(Book *b)
{
    cout << "Id: " << b->id << endl;
    cout << "Authors: " << b->authors << endl;
    cout << "Best sellers rank: " << b->best_sellers_rank << endl;
    cout << "Categories: " << b->categories << endl;
    cout << "Edition: " << b->edition << endl;
    cout << "ISBN 10: " << b->isbn10 << endl;
    cout << "ISBN 13: " << b->isbn13 << endl;
    cout << "Rating Average: " << b->rating_avg << endl;
    cout << "Rating count: " << b->rating_count << endl;
    cout << "Title: " << b->title << endl;
    cout << endl;
}

void print_author(Author *a){
    cout << "Id: " << a->id << endl;
    cout << endl;
}

void print_book_q(Book *b)
{
    cout << b->id << endl;
}

void print_book_t(Book *b)
{
    cout << b->title << endl;
}

void print_book_a(Book *b)
{
    cout << b->authors << endl;
}

void print_message(TRACE_TYPE type, string message)
{
    switch (type)
    {
    case INFO:
        cout << "INFO: " << message;
        break;
    case ERROR:
        cout << "ERROR: " << message << endl;
        break;
    default:
        break;
    }
}

void trace(TRACE_TYPE type, string message)
{
    print_message(type, message);
    cout << endl;
}

void trace_i(TRACE_TYPE type, string message, int param)
{
    print_message(type, message);
    cout << param << endl;
}

void trace_s(TRACE_TYPE type, string message, string param)
{
    print_message(type, message);
    cout << param << endl;
}

void trace_d(TRACE_TYPE type, string message, double param)
{
    print_message(type, message);
    cout << param << endl;
}
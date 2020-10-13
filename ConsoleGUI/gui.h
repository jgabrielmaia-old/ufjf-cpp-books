#ifndef GUI
#define GUI

#include "../Model/book.h"
#include <stdio.h>
#include <iostream>
using namespace std;

enum TRACE_TYPE
{
    INFO = 1,
    ERROR
};

void print_book(Book *b);
void print_book_q(Book *b);
void trace(TRACE_TYPE type, string message, int param = 0);

#endif
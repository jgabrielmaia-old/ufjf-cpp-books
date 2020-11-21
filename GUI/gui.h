#ifndef GUI
#define GUI

#include "../Model/book.h"
#include "../Model/author.h"
#include <stdio.h>
#include <iostream>
using namespace std;

enum TRACE_TYPE
{
    INFO = 1,
    ERROR
};

const string empty_str = string();

void print_book(Book *b);
void print_author(Author *a);
void print_book_q(Book *b);
void print_book_t(Book *b);
void print_book_a(Book *b);
void print_message(TRACE_TYPE type, string message);
void trace(TRACE_TYPE type, string message);
void trace_i(TRACE_TYPE type, string message, int param);
void trace_s(TRACE_TYPE type, string message, string param);
void trace_d(TRACE_TYPE type, string message, double param);

#endif
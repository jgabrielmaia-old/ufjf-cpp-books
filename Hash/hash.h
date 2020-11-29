#ifndef HASH
#define HASH

#include "../Model/author.h"
#include "../Model/book.h"
#include "../GUI/gui.h"
#include <string>
using namespace std;

const int PRIME = 7;

class HashNode
{
public:
    int hit_count;
    int key;
    Author *value;
    HashNode *next;
    HashNode();
    HashNode(Author *value);
};

class HashTable
{
public:
    int capacity;
    HashNode **nodes;
    HashTable(int capacity);
    ~HashTable();

    int hash_int(int number, int capacity);

    void insert(Author *value);
    HashNode *fetch(int key);
    void print_hash_table();
    void print_hash_table_hits();
    void search_authors_in_books(Book **books, int library_size);
};

void swap_values(HashNode *a, HashNode *b);

#endif
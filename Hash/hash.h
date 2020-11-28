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
    string key;
    Author *value;
    HashNode *next;
    HashNode();
    HashNode(Author *value);
};

class HashTable
{
private:
    int capacity;

public:
    HashNode **nodes;
    HashTable(int capacity);
    ~HashTable();

    int hashString(string s, int capacity);

    void insert(Author *value);
    HashNode *fetch(string key);
    void print_hash_table();
    void print_hash_table_hits();
    void search(HashTable table, Book **books, int library_size);
};

#endif
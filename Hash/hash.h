#include "../Model/book.h"

int hashString(string s, int capacity) {
    return 0;
}

int HashBook(Book *b, int capacity) {
    return 0;
}

template <typename T>
class HashNode
{
public:
    int hit_count;
    HashNode *next;
    int key;
    T value;
    HashNode(int key, T value, HashNode<T> *next);
};

template <typename T>
class HashTable
{
private:
    int capacity;

public:
    HashNode<T> **nodes;
    HashTable(int capacity);
    ~HashTable();

    void insert(int key, T value);
    T fetch(int key);
};

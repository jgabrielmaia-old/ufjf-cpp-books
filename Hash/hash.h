#include "../Model/book.h"

const int PRIME = 49999;

int hashString(string s, int capacity) {
    long hash = 0;
    for (unsigned i = 0; i < s.length(); i++) {
        hash = (PRIME * hash + s[i]) % capacity;
    }
    return hash;
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
    string key;
    T value;
    HashNode(string key, T value, HashNode<T> *next);
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

    void insert(T value);
    T fetch(T key);
};

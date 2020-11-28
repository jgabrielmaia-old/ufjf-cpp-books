#ifndef HASH
#define HASH

#include "../Model/book.h"
#include <string>
using namespace std;

const int PRIME = 49999;

template <class T>
class HashNode
{
public:
    int hit_count;
    string key;
    T value;
    HashNode();
};

template <class T>
class HashTable
{
private:
    int capacity;

public:
    HashNode<T> **nodes;
    HashTable(int capacity);
    ~HashTable();

    void insert(T value);
    T fetch(string key);
    int hashString(string s, int capacity);
    HashTable<T> *entites_to_hash(T **entities, int entity_list_size);
};

#endif
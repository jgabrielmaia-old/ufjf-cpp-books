#include "hash.h"
#include <cstddef>
#include <stdlib.h>
#include <iostream>
using namespace std;

const string EMPTY_STR = "";

template <class T>
int HashTable<T>::hashString(string s, int capacity) {
    long hash = 0;
    for (unsigned i = 0; i < s.length(); i++) {
        hash = (PRIME * hash + s[i]) % capacity;
    }
    return hash;
}

template <class T>
HashNode<T>::HashNode()
{
    this->hit_count = 0;
}

template <class T>
HashTable<T>::HashTable(int capacity)
{
    this->capacity = capacity;
    nodes = (HashNode<T> **)malloc(this->capacity * sizeof(HashNode<T> *));

    for (size_t i = 0; i < capacity; i++)
    {
        nodes[i] = nullptr;
    }
}

template <class T>
HashTable<T>::~HashTable()
{
    for (size_t i = 0; i < this->capacity; i++)
    {
        HashNode<T> *current = nodes[i];

        delete current;
    }

    delete nodes;
}

template <class T>
void HashTable<T>::insert(T value)
{
    if(fetch(value) == EMPTY_STR){
        int hash = this->hashString(value, this->capacity);
        HashNode<T> *new_author = this->nodes[hash];
        new_author->hit_count++;
        new_author->value = value;
        this->nodes[hash] = new_author;
    }

}

template <class T>
T HashTable<T>::fetch(string key)
{
    int hash = this->hashString(key, this->capacity);
    if(this->nodes[hash]->key == key) {

        nodes[hash]->hit_count++;

        return nodes[hash]->value;
    }

    return NULL;
}

template <class T>
HashTable<T> HashTable<T>::*entites_to_hash(T **entities, int entity_list_size)
{
    HashTable<T> *hashTable = new HashTable<T>(entity_list_size);

    for (size_t i = 0; i < entity_list_size; i++)
    {
        hashTable->insert(entities[i]);
    }

    return hashTable;
}
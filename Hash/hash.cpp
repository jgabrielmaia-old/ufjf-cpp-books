#include "hash.h"
#include <cstddef>
#include <stdlib.h>
#include <iostream>
using namespace std;

template <>
HashNode<Book *>::HashNode(string key, Book *value, HashNode<Book *> *next)
{
    this->key = key;
    this->value = value;
    this->next = next;
    this->hit_count = 0;
}

template <>
HashNode<string>::HashNode(string key, string value, HashNode<string> *next)
{
    this->key = key;
    this->value = value;
    this->next = next;
    this->hit_count = 0;
}

template <>
HashTable<Book *>::HashTable(int capacity)
{
    this->capacity = capacity;
    nodes = (HashNode<Book *> **)malloc(this->capacity * sizeof(HashNode<Book *> *));

    for (size_t i = 0; i < capacity; i++)
    {
        nodes[i] = nullptr;
    }
}

template <>
HashTable<Book *>::~HashTable()
{
    for (size_t i = 0; i < this->capacity; i++)
    {
        HashNode<Book *> *current = nodes[i];
        while (current != NULL)
        {
            HashNode<Book *> *to_destroy = current;
            current = current->next;
            delete to_destroy;
        }
    }

    delete nodes;
}

template <>
HashTable<string *>::~HashTable()
{
    for (size_t i = 0; i < this->capacity; i++)
    {
        HashNode<string *> *current = nodes[i];
        while (current != NULL)
        {
            HashNode<string *> *to_destroy = current;
            current = current->next;
            delete to_destroy;
        }
    }

    delete nodes;
}

template <>
HashTable<string *>::HashTable(int capacity)
{
    this->capacity = capacity;
    nodes = (HashNode<string *> **)malloc(this->capacity * sizeof(HashNode<string *> *));

    for (size_t i = 0; i < capacity; i++)
    {
        nodes[i] = nullptr;
    }
}

template <>
void HashTable<Book *>::insert(Book *value)
{

}

template <>
Book * HashTable<Book *>::fetch(Book *key)
{
    return 0;
}

template <>
void HashTable<string>::insert(string value)
{
    string try_fetch;
    try_fetch = fetch(value);

}

template <>
string HashTable<string>::fetch(string key)
{
    int hash = hashString(key, this->capacity);
    if((this->nodes[hash] != NULL) && (this->nodes[hash]->key == key)) {
        return nodes[hash]->value;
    }
    else {
        HashNode<string> *current = this->nodes[hash];

        while(current != NULL)
        {
            if(current->key == key){
                return current->value;
            }

            current->hit_count++;
            current = current->next;
        }
    }

    return "operation-failed-not-found";
}
#include "hash.h"
#include <cstddef>
#include <stdlib.h>
#include <iostream>
using namespace std;

template <>
HashNode<Book *>::HashNode(int key, Book *value, HashNode<Book *> *next)
{
    this->key = key;
    this->value = value;
    this->next = next;
    this->hit_count = 0;
}

template <>
HashNode<string>::HashNode(int key, string value, HashNode<string> *next)
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
void HashTable<Book *>::insert(int key, Book *value)
{
}

template <>
Book * HashTable<Book *>::fetch(int key)
{
    return nullptr;
}

template <>
void HashTable<string>::insert(int key, string value)
{
}

template <>
string HashTable<string>::fetch(int key)
{
    return "";
}
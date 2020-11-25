#include "hash.h"
#include "../Model/book.h"
#include "../Model/author.h"
#include <cstddef>
#include <stdlib.h>

template <>
HashNode<Book *>::HashNode(int key, Book *value, HashNode<Book *> *next)
{
    this->key = key;
    this->value = value;
    this->next = next;
    this->hit_count = 0;
}

template <>
HashNode<Author *>::HashNode(int key, Author *value, HashNode<Author *> *next)
{
    this->key = key;
    this->value = value;
    this->next = next;
    this->hit_count = 0;
}

template <>
HashTable<Book *>::HashTable(int capacity){
    this->capacity = capacity;
    nodes = (HashNode<Book *> **)malloc(this->capacity * sizeof(HashNode<Book *> *));

    for (size_t i = 0; i < capacity; i++)
    {
        nodes[i] = nullptr;
    }

}

template <>
HashTable<Author *>::HashTable(int capacity){
    this->capacity = capacity;
    nodes = (HashNode<Author *> **)malloc(this->capacity * sizeof(HashNode<Author *> *));

    for (size_t i = 0; i < capacity; i++)
    {
        nodes[i] = nullptr;
    }

}
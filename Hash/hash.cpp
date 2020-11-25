#include "hash.h"
#include "../Model/book.h"
#include "../Model/author.h"
#include <cstddef>

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
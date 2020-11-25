#include "hash.h"
#include "../Model/book.h"
#include "../Model/author.h"

template <>
HashNode<Book *>::HashNode(int key, Book *value)
{
    this->key = key;
    this->value = value;
}

template <>
HashNode<Author *>::HashNode(int key, Author *value)
{
    this->key = key;
    this->value = value;
}
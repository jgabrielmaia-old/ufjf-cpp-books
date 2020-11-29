#include "hash.h"
#include <cstddef>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

const string EMPTY_STR = "";

int HashTable::hash_int(int number, int capacity)
{
    int hash = 0;
    if (number < 0)
        number = -number;

    hash = (PRIME * number) % capacity;
    return hash;
}

HashNode::HashNode(Author *value)
{
    this->value = (Author *)malloc(sizeof(Author));
    this->value->id = value->id;
    strcpy(this->value->name, value->name);
    this->key = value->id;
    this->hit_count = 0;
    this->next = nullptr;
}

HashTable::HashTable(int capacity)
{
    this->capacity = capacity;
    nodes = (HashNode **)malloc(this->capacity * sizeof(HashNode *));

    for (size_t i = 0; i < capacity; i++)
    {
        nodes[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    for (size_t i = 0; i < this->capacity; i++)
    {
        HashNode *current = nodes[i];

        delete current;
    }

    delete nodes;
}

void HashTable::insert(Author *to_insert)
{
    int hash = this->hash_int(to_insert->id, this->capacity);

    HashNode *current = this->nodes[hash];

    HashNode *new_node = new HashNode(to_insert);

    if (current != nullptr)
    {
        new_node->next = current;
    }

    this->nodes[hash] = new_node;
}

HashNode *HashTable::fetch(int key)
{
    int hash = this->hash_int(key, this->capacity);

    if(hash < 0)
        cout << hash;

    if (this->nodes[hash] == nullptr)
        return nullptr;

    if (this->nodes[hash]->key == key)
    {
        nodes[hash]->hit_count++;
        return nodes[hash];
    }
    else
    {
        HashNode *current = this->nodes[hash];
        HashNode *head = this->nodes[hash];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->hit_count++;

                return current;
            }

            current = current->next;
        }
    }
    return nullptr;
}

void swap_values(HashNode *a, HashNode *b)
{
    int aux_key = a->key;
    int aux_hit_count = a->hit_count;
    Author *aux_value = a->value;

    a->key = b->key;
    a->hit_count = b->hit_count;
    a->value = b->value;

    b->key = aux_key;
    b->hit_count = aux_hit_count;
    b->value = aux_value;
}

void HashTable::print_hash_table()
{
    for (size_t i = 0; i < this->capacity; i++)
    {
        cout << i << ": ";

        if (this->nodes[i] != nullptr)
        {
            HashNode *current = this->nodes[i];
            while (current != nullptr)
            {
                print_author(current->value);
                if (current->next != nullptr)
                    cout << " > ";
                current = current->next;
            }
            cout << endl;
        }
        else
        {
            cout << "empty" << endl;
        }
    }
}

void HashTable::print_hash_table_hits()
{
    for (size_t i = 0; i < this->capacity; i++)
    {
        cout << i << ": ";

        if (this->nodes[i] != nullptr)
        {
            HashNode *current = this->nodes[i];
            while (current != nullptr)
            {
                cout << current->hit_count;

                if (current->next != nullptr)
                    cout << " > ";
                current = current->next;
            }
            cout << endl;
        }
        else
        {
            cout << "empty" << endl;
        }
    }
}

void HashTable::search_authors_in_books(Book **books, int library_size)
{
    for (size_t i = 0; i < library_size; i++)
    {
        if(books[i] == nullptr){
            continue;
        }

        if(books[i]-> authors == nullptr){
            continue;
        }

        for (size_t j = 0; j < 10; j++)
        {
            int current_author_id = books[i]->authors[j];
            if (current_author_id == 0)
                break;

            this->fetch(current_author_id);
        }
    }
};
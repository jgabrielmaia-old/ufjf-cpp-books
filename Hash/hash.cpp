#include "hash.h"
#include <cstddef>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

const string EMPTY_STR = "";

int HashTable::hashString(string s, int capacity)
{
    int hash = 0;
    for (int i = 0; i < s.length(); i++)
    {
        hash = (PRIME * (s[i] * s[i]) + hash) % capacity;
    }
    return hash;
}

HashNode::HashNode(Author *value)
{
    this->value = (Author *)malloc(sizeof(Author));
    strcpy(this->value->id, value->id);
    strcpy(this->value->name, value->name);
    this->key = value->name;
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
    int hash = this->hashString(to_insert->name, this->capacity);
    HashNode *current = this->nodes[hash];

    HashNode *new_node = new HashNode(to_insert);

    if (current != nullptr)
    {
        new_node->next = current;
    }

    this->nodes[hash] = new_node;
}

HashNode *HashTable::fetch(string key)
{
    int hash = hashString(key, this->capacity);

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

void HashTable::search(HashTable table, Book **books, int library_size)
{

};
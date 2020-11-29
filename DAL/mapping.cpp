#include "mapping.h"

void entities_to_hash(Author **entities, HashTable *hashTable, int entity_list_size)
{
    for (size_t i = 0; i < entity_list_size; i++)
    {
        hashTable->insert(entities[i]);
    }
}

HashedAuthor **hashed_authors_to_list(HashTable *hashTable, int authors_list_size)
{
    HashedAuthor **frequency_list = (HashedAuthor **)malloc(authors_list_size * sizeof(HashedAuthor *));

    int j = 0;
    for (size_t i = 0; i < hashTable->capacity; i++)
    {
        if (hashTable->nodes[i] != nullptr)
        {
            HashNode *current = hashTable->nodes[i];
            while (current != nullptr)
            {
                HashedAuthor *hashed_current = (HashedAuthor *)malloc(sizeof(HashedAuthor));
                strcpy(hashed_current->name, current->value->name);
                hashed_current->hit_count = current->hit_count;

                current = current->next;

                frequency_list[j++] = hashed_current;
            }
        }
    }

    return frequency_list;
}
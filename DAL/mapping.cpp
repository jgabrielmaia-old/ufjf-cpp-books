#include "mapping.h"

void entities_to_hash(Author **entities, HashTable *hashTable, int entity_list_size)
{
    for (size_t i = 0; i < entity_list_size; i++)
    {
        hashTable->insert(entities[i]);
    }
}
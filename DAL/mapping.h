#ifndef MAPPING
#define MAPPING

#include "../Model/author.h"
#include "../Hash/hash.h"

void entities_to_hash(Author **entities, HashTable *hashTable, int entity_list_size);

#endif
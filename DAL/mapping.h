#ifndef MAPPING
#define MAPPING

#include <cstring>

#include "../Model/author.h"
#include "../Hash/hash.h"
#include "../Model/hashed_author.h"

void entities_to_hash(Author **entities, HashTable *hashTable, int entity_list_size);
HashedAuthor **hashed_authors_to_list(HashTable *hashTable, int authors_list_size);

#endif
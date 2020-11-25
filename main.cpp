#include "Model/book.h"
#include "Model/author.h"
#include "Model/mapping.h"
#include "GUI/gui.h"
#include "DAL/csv_reader.h"
#include "DAL/input_reader.h"
#include "DAL/output_writer.h"
#include "Benchmark/benchmark.h"
#include "Hash/hash.h"

#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Book *book = (Book *)malloc(sizeof(Book));

    HashNode<Book *> *test = (HashNode<Book *> *)malloc(sizeof(HashNode<Book *>));

    test = new HashNode<Book *>(1, book, nullptr);

    HashTable<Book *> *table = (HashTable<Book *> *)malloc(sizeof(HashTable<Book *>));

    table = new HashTable<Book *>(10);

    for (size_t i = 0; i < 10; i++)
    {
        cout << table->nodes[i] << endl;
    }

    return 0;
}
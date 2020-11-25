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

    cout << test->key << endl;
    cout << test->value << endl;
    cout << test->next << endl;
    cout << test->hit_count << endl;

    return 0;
}
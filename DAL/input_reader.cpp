#include "input_reader.h"

#include <stdlib.h>
#include <string>

int *read_input(FILE *stream, int size)
{
    int i = 0;
    char line[1024] = {0};
    int *input = (int *)malloc(size * sizeof(int));

    while (i < size && fgets(line, 1024, stream))
    {
        input[i++] = atoi(line);
    }

    return input;
}

int get_test_size(FILE *stream)
{
    char line[1024] = {0};
    fgets(line, 1024, stream);

    return atoi(line);
}
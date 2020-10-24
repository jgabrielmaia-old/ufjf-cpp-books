#ifndef INPUT_READER
#define INPUT_READER

#include "../GUI/gui.h"

#include <stdio.h>

int *read_input(FILE *stream, int size);
int get_test_size(FILE *stream);

#endif
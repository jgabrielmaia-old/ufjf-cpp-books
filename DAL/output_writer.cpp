#include "output_writer.h"

#include <iostream>
#include <fstream>

void write_to_file(string filename, string content) {
    ofstream to_write(filename);
    to_write << content;
    to_write.close();
    return;
}
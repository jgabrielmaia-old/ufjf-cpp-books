#include "output_writer.h"

#include <iostream>
#include <fstream>

void write_to_file(string filename, string content) {
    ofstream myfile;
    myfile.open (filename);
    myfile << content;
    myfile.close();
}
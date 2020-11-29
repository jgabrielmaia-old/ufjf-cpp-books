#include "parsing.h"
#include "../Model/author.h"

#include <stdlib.h>

int *parse_author_ids(string authors)
{
    int *author_ids = (int *)malloc(10 * sizeof(int));
    for (size_t i = 0; i < 10; i++)
    {
        author_ids[i] = 0;
    }

    int count = 0;
    for (size_t i = 0; i < authors.length(); i++)
    {
        if(authors[0] != '[')
            break;

        string author_id_str;
        while (authors[++i] != ']')
        {
            if (authors[i] == ',')
                break;
            author_id_str += authors[i];
        }

        if (author_id_str.length() == 0){
            author_ids[count++] = -1;
        }
        else{
            author_ids[count++] = stoi(author_id_str);
        }
    }

    return author_ids;
}
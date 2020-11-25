#ifndef RBTREE_NODE
#define RBTREE_NODE

#include "color.h"

typedef struct rbtree_node
{
    color color;
    void *key;
    void *value;
    rbtree_node *left, *right, *parent;
}*node;

#endif
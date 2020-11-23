enum color { RED, BLACK };

typedef struct rbtree_node
{
    enum color color;
    void *key;
    void *value;
    rbtree_node *left, *right, *parent;
}*node;
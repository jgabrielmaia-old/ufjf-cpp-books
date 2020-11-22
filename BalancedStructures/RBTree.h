
#include "RBTree_Node.h"
#include "RBTree_t.h"

class RBTree
{
    public:
        typedef int (*compare_func)(void* left, void* right);
        rbtree rbtree_create();
        void* rbtree_lookup(rbtree t, void* , compare_func compare);
        void rbtree_insert(rbtree t, void* , void* , compare_func compare);
        void rbtree_delete(rbtree t, void* , compare_func compare);
        node grandparent(node n);
        node sibling(node n);
        node uncle(node n);
        void verify_properties(rbtree t);
        void verify_property_1(node root);
        void verify_property_2(node root);
        color node_color(node n);
        void verify_property_4(node root);
        void verify_property_5(node root);
        void verify_property_5_helper(node n, int , int*);
        node new_node(void* key, void* , color , node , node);
        node lookup_node(rbtree t, void* , compare_func compare);
        void rotate_left(rbtree t, node n);
        void rotate_right(rbtree t, node n);
        void replace_node(rbtree t, node oldn, node newn);
        void insert_case1(rbtree t, node n);
        void insert_case2(rbtree t, node n);
        void insert_case3(rbtree t, node n);
        void insert_case4(rbtree t, node n);
        void insert_case5(rbtree t, node n);
        node maximum_node(node root);
        void delete_case1(rbtree t, node n);
        void delete_case2(rbtree t, node n);
        void delete_case3(rbtree t, node n);
        void delete_case4(rbtree t, node n);
        void delete_case5(rbtree t, node n);
        void delete_case6(rbtree t, node n);
};
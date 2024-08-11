
#ifndef BST_H
#define BST_H

typedef struct bst_node {
    int value;
    struct bst_node* left;
    struct bst_node* right;
} bst_node_t;

bst_node_t* bstree_create_node(int value);
bst_node_t* bstree_insert(bst_node_t* root, int value);
int compare(int a, int b);

#endif
#include "bst.h"

#include <stdlib.h>

bst_node_t* bstree_create_node(int value) {
    bst_node_t* new_node = (bst_node_t*)malloc(sizeof(bst_node_t));
    if (new_node) {
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

int compare(int a, int b) { return (a > b) - (a < b); }

bst_node_t* bstree_insert(bst_node_t* root, int value) {
    if (root == NULL) {
        return bstree_create_node(value);
    }

    if (compare(value, root->value) < 0) {
        root->left = bstree_insert(root->left, value);
    } else if (compare(value, root->value) > 0) {
        root->right = bstree_insert(root->right, value);
    }

    return root;
}
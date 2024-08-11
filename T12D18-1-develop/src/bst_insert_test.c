
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void inorder_print(bst_node_t* root);
void test_bstree_insert();

int main() {
    test_bstree_insert();
    return 0;
}

void inorder_print(bst_node_t* root) {
    if (root != NULL) {
        inorder_print(root->left);
        printf("%d ", root->value);
        inorder_print(root->right);
    }
}
void test_bstree_insert() {
    bst_node_t* root = NULL;

    int values1[5] = {30, 20, 40, 10, 25};
    for (int i = 0; i < 5; i++) {
        printf("insert %d to bst\n", values1[i]);
        root = bstree_insert(root, values1[i]);
        printf("current: ");
        inorder_print(root);
        printf("\n");
    }
    printf("\n");
    root = NULL;
    int values2[5] = {50, 30, 70, 20, 40};
    for (int i = 0; i < 5; i++) {
        printf("insert %d to bst\n", values2[i]);
        root = bstree_insert(root, values2[i]);
        printf("current: ");
        inorder_print(root);
        printf("\n");
    }
}
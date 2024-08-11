

#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void test_bstree_create_node();

int main() {
    test_bstree_create_node();
    test_bstree_insert();
    return 0;
}
void test_bstree_create_node() {
    int test_values[2] = {5, 40};
    for (int i = 0; i < 2; i++) {
        bst_node_t* node = bstree_create_node(test_values[i]);
        if (node) {
            printf("node: %d\n", node->value);
            free(node);
        } else {
            printf("fail with value: %d\n", test_values[i]);
        }
    }
}

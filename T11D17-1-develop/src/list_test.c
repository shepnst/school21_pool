#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"
void printList(struct Node* root);

int main() {
    struct door door1 = {4, 1};
    struct door door2 = {6, 0};
    struct door door3 = {7, 1};
    struct Node* list = init(&door1);

    struct Node* second = add_door(list, &door2);
    struct Node* third = add_door(second, &door3);
    printList(list);
    printf(" SUCCESS");
    printf("\n");
    list = remove_door(third, list);
    printList(list);
    printf(" SUCCESS");
    destroy(list);
    return 0;
}

void printList(struct Node* root) {
    struct Node* current = root;
    while (current != NULL) {
        printf("%d ", current->data->id);
        current = current->next;
    }
}
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

struct Node* init(struct door* door) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = door;
    new_node->next = NULL;
    return new_node;
}

struct Node* add_door(struct Node* elem, struct door* door) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = door;
    new_node->next = NULL;
    if (elem == NULL) {
        return new_node;
    }
    elem->next = new_node;
    return new_node;
}

struct Node* find_door(int door_id, struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    struct Node* curr = root;
    while (curr) {
        if (curr->data->id == door_id) {
            return curr;
        } else {
            curr = curr->next;
        }
    }
    return NULL;
}

struct Node* remove_door(struct Node* elem, struct Node* root) {
    struct Node* current = root;
    struct Node* previous = NULL;

    if (current != NULL && current == elem) {
        return current;
        free(current);
    }

    while (current->next != NULL && current != elem) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return NULL;
    }
    previous->next = current->next;
    free(elem);
    return root;
}

void destroy(struct Node* root) {
    struct Node* curr = root;
    struct Node* next_node;
    while (curr != NULL) {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }
}
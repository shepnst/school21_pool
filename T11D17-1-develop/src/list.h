#ifndef LIST
#define LIST

struct Node {
    struct door* data;
    struct Node* next;
};

struct Node* init(struct door* door);
struct Node* add_door(struct Node* elem, struct door* door);
struct Node* find_door(int door_id, struct Node* root);
struct Node* remove_door(struct Node* elem, struct Node* root);
void destroy(struct Node* root);

#endif

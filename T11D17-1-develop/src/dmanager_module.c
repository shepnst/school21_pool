#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void status_closed(struct door* doors);
void sort(struct door* doors);
void output(struct door* doors);
int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    status_closed(doors);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors) {
    for (int p = 0; p < DOORS_COUNT - 1; p++) {
        for (int b = 0; b < DOORS_COUNT - 1; b++) {
            int temp;
            if (doors[b].id > doors[b + 1].id) {
                temp = doors[b].id;
                doors[b].id = doors[b + 1].id;
                doors[b + 1].id = temp;
            }
        }
    }
}

void status_closed(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i != DOORS_COUNT - 1) {
            printf("%d", doors[i].id);
            printf(",");
            printf(" %d\n", doors[i].status);
        } else {
            printf("%d", doors[i].id);
            printf(",");
            printf(" %d", doors[i].status);
        }
    }
}
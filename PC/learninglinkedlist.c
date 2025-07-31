#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int value;
    struct NODE *next;
} NODE;

NODE *createNode(void);
void addAtEnd(int value, NODE *start);
void showList(NODE *start);
void removeNode(int value, NODE *start);

int main() {
    NODE *start = createNode();
    addAtEnd(10, start);
    addAtEnd(20, start);
    addAtEnd(12319239, start);
    removeNode(10, start);
    showList(start);
}

NODE *createNode() {
    NODE *start = (NODE *)malloc(sizeof(NODE));
    if (start == NULL)
        printf("malloc error\n");
    start->value =
        0; // That value doesn't matter, cause its the head of linked list
    start->next = NULL;
    return start;
}

void addAtEnd(int value, NODE *start) {
    // prox-> != NULL; fim = fim->prox;
    NODE *lastNode = start;
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
        printf("malloc error\n");
    newNode->value = value;
    newNode->next = NULL;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void showList(NODE *start) {
    NODE *node;
    for (node = start->next; node != NULL; node = node->next)
        printf("%d\n", node->value);
}

void removeNode(int value, NODE *start) {
    NODE *actual = start;
    NODE *next = start->next;

    while (next != NULL && next->value != value) {
        actual = next;
        next = next->next;
    }
    if (next != NULL) {
        actual->next = next->next;
        free(next);
    }
}

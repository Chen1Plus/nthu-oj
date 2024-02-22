#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

void deleteNode(Node** nd, int data) {
    if (data == 0) return;

    Node* prev   = NULL;
    Node* target = *nd;
    for (int i = 0; i < data - 1; i++) {
        prev   = target;
        target = target->next;
        if (target == NULL) return;
    }

    if (prev == NULL)
        *nd = target->next;
    else
        prev->next = target->next;

    free(target);
}

Node* createList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    scanf("%d", &head->data);

    int data;
    Node* temp = head;
    while (1) {
        scanf("%d", &data);
        if (data <= -1) break;

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp       = newNode;
    }

    return head;
}
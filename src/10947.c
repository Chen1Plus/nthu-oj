#include <stdio.h>
#include <stdlib.h>

#include "10947_function.h"

void printList(Node *head) {
    Node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
}

void freeList(Node *head) {
    for (Node *temp = head; temp != NULL; temp = head) {
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = createList();

    int data;
    while (1) {
        scanf("%d", &data);
        if (data <= -1) break;
        deleteNode(&head, data);
    }

    printList(head);
    freeList(head);
    return 0;
}

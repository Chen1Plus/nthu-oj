#include <stdlib.h>


typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

void Push(Node** ptr_head, int x) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = *ptr_head;
    *ptr_head = new_node;
}

void Pop(Node** ptr_head) {
    Node* temp = *ptr_head;
    if (temp == NULL) return;
    *ptr_head = temp->next;
    free(temp);
}

void Reverse_List(Node** ptr_head) {
    Node* prev = NULL;
    Node* curr = *ptr_head;
    Node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *ptr_head = prev;
}

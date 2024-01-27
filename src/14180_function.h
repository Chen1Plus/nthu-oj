#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void insert(Node** pos, Node** back, int idx) {
    Node* new    = malloc(sizeof(Node));
    new->idx     = idx;
    new->next    = (*pos)->next;
    (*pos)->next = new;
    if (*back == *pos) *back = new;
}

void AddBack(Node** head, Node** back, int* arr, int n) {
    for (int i = 0; i < n; i++) insert(back, back, arr[i]);
}

void CircularInsert(Node** head, Node** back, int n, int m) {
    Node* pos = (*head)->next;
    while (n--) {
        insert(&pos, back, m);
        int cnt = pos->idx;
        while (cnt--) pos = pos->next ? pos->next : (*head)->next;
    }
}
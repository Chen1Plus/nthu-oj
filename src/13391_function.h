#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

Node* CreateNode(int num) {
    Node* tmp = malloc(sizeof(Node));
    tmp->idx = num, tmp->next = NULL;
    return tmp;
}

void AddFront(Node** head, Node** back, int num) {
    Node* tmp = CreateNode(num);
    if (*head == *back && (*head)->idx == -1)
        (*back) = tmp;
    else
        tmp->next = (*head)->next;
    (*head)->next = tmp;
}

void AddBack(Node** head, Node** back, int num) {
    Node* tmp = CreateNode(num);
    (*back)->next = tmp;
    *back = tmp;
}

void DeleteFront(Node** head, Node** back) {
    if ((*head)->next == NULL) return;
    Node* tmp = (*head)->next;
    (*head)->next = tmp->next;
    free(tmp);
}

void Delete(Node** head, Node** back, int num) {
    Node *del, *tmp;
    tmp = *head;
    while (tmp->next) {
        del = tmp->next;
        if (del->idx == num) {
            if (!del->next) *back = tmp;
            tmp->next = del->next;
            free(del);
        } else
            tmp = tmp->next;
    }
}

void Swap(Node** head, Node** back) {
    if (!(*head)->next || !(*head)->next->next) return;
    Node *prev = (*head)->next, *curr = (*head)->next->next, *next;
    prev->next = NULL;
    *back = prev;
    while (curr->next) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    (*head)->next = curr;
}
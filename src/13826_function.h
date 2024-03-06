#include <stdlib.h>

typedef struct _Node {
    int serial, stu_id;
    char name[1001];
    struct _Node* next;
} Node;

void swap(Node* a, Node* b) {
    Node* tmp = a->next;
    a->next   = b->next;
    b->next   = tmp;

    tmp           = a->next->next;
    a->next->next = b->next->next;
    b->next->next = tmp;
}

void eFormSort(Node* head) {
    Node* pre = malloc(sizeof(Node));
    pre->next = head;

    for (Node* i = pre; i->next->next; i = i->next)
        for (Node* j = i->next; j->next; j = j->next)
            if (i->next->serial > j->next->serial)
                if (j == i->next) {
                    swap(i, j);
                    j = i->next;
                } else
                    swap(i, j);
}

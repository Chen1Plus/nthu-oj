#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *new_node(char data, Node *prev, Node *next) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data, node->prev = prev, node->next = next;
    return node;
}

int main() {
    int t;
    Node *head = new_node(0, NULL, NULL);
    scanf("%d", &t);
    while (t--) {
        int s;
        Node *cur = head;
        scanf("%d", &s);
        while (s--) {
            char c;
            scanf(" %c", &c);
            if (c >= 'a' && c <= 'z') {
                Node *new = new_node(c, cur, cur->next);
                if (cur->next) cur->next->prev = new;
                cur = cur->next = new;
            } else if (c == 'L' && cur->prev)
                cur = cur->prev;
            else if (c == 'R' && cur->next)
                cur = cur->next;
            else if (c == 'B' && cur->prev) {
                cur->prev->next = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                Node *del = cur;
                cur       = cur->prev;
                free(del);
            }
        }

        for (Node *p = head->next; p;) {
            Node *tmp = p;
            p         = p->next;
            printf("%c", tmp->data);
            free(tmp);
        }
        printf("\n");
        head->next = NULL;
    }
    free(head);
}
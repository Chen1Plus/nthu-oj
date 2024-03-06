#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    char ch;
    struct _Node *next;
} Node;

Node *head[100005], *tail[100005], *rev_head[100005], *rev_tail[100005];

Node *input() {
    Node *new = malloc(sizeof(Node));
    scanf(" %c", &new->ch);
    new->next = NULL;
    return new;
}

Node *node_cpy(Node *src) {
    Node *new = malloc(sizeof(Node));
    memcpy(new, src, sizeof(Node));
    return new;
}

// only used in function swap
#define swap_macro(arr)  \
    tmp      = (arr)[a]; \
    (arr)[a] = (arr)[b]; \
    (arr)[b] = tmp;

void swap(int a, int b) {
    Node *tmp;
    swap_macro(head);
    swap_macro(tail);
    swap_macro(rev_head);
    swap_macro(rev_tail);
}

void append(int a, int b) {
    if (!head[a]) return;
    if (!head[b]) {
        swap(a, b);
        return;
    }

    tail[b]->next     = head[a];
    tail[b]           = tail[a];
    rev_tail[a]->next = rev_head[b];
    rev_head[b]       = rev_head[a];
    head[a] = tail[a] = rev_head[a] = rev_tail[a] = NULL;
}

void reverse(int a) {
    if (head[a] == NULL) return;

    Node *tmp   = head[a];
    head[a]     = rev_head[a];
    rev_head[a] = tmp;
    tmp         = tail[a];
    tail[a]     = rev_tail[a];
    rev_tail[a] = tmp;
}

int main() {
    int n, q;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        if (!k) continue;

        Node *cur = head[i] = input();
        Node *rev_cur = rev_tail[i] = node_cpy(cur);
        while (--k) {
            cur->next     = input();
            cur           = cur->next;
            Node *prev    = rev_cur;
            rev_cur       = node_cpy(cur);
            rev_cur->next = prev;
        }
        tail[i]     = cur;
        rev_head[i] = rev_cur;
    }

    scanf("%d", &q);
    while (q--) {
        int op, a, b;
        scanf("%d %d", &op, &a);
        if (op != 4) scanf("%d", &b);

        switch (op) {
            case 1:
                append(b, a);
                swap(a, b);
                break;
            case 2:  append(a, b); break;
            case 3:  swap(a, b); break;
            case 4:  reverse(a); break;
            default: break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (Node *cur = head[i]; cur; cur = cur->next) printf("%c", cur->ch);
        printf("\n");
    }
}

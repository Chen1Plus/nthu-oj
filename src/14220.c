#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int idx;
    struct Node *prev;
    struct Node *next;
} Node;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    Node **arr = (Node **)malloc(sizeof(Node *) * (n + 1));
    arr[0]     = (Node *)malloc(sizeof(Node));
    for (int i = 1; i <= n; i++) {
        arr[i]      = (Node *)malloc(sizeof(Node));
        arr[i]->idx = i, arr[i]->prev = arr[i - 1], arr[i - 1]->next = arr[i];
    }
    arr[1]->prev = NULL;
    free(arr[0]);

    int t, a, b;
    while (k--) {
        scanf("%d %d %d", &t, &a, &b);
        t--;

        if (!(arr[a] && (t ? arr[a]->prev : arr[a]->next))) {
            printf("Penguin07 QQ\n");
            continue;
        };

        Node *head, *last;
        if (t) {
            head = last = arr[a]->prev;
            while (--b && head->prev) head = head->prev;
        } else {
            head = last = arr[a]->next;
            while (--b && last->next) last = last->next;
        }

        if (head->prev) head->prev->next = last->next;
        if (last->next) last->next->prev = head->prev;
        head->prev = last->next = NULL;

        printf("%d", head->idx);
        for (Node *tmp, *cur = head->next; cur; cur = tmp) {
            printf(" %d", cur->idx);
            tmp           = cur->next;
            arr[cur->idx] = NULL;
            free(cur);
        }
        printf("\n");
        arr[head->idx] = NULL;
        free(head);
    }

    for (; n; n--)
        if (arr[n]) free(arr[n]);
    free(arr);
    return 0;
}

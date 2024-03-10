#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int idx;
    struct _Node *prev;
    struct _Node *next;
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

    while (k--) {
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);

        if (!(arr[a] && (t == 1 ? arr[a]->next : arr[a]->prev))) {
            printf("Penguin07 QQ\n");
            continue;
        };

        Node *head, *last;
        head = last = t == 1 ? arr[a]->next : arr[a]->prev;
        for (int i = 1; i < b && (t == 1 ? last->next : head->prev); i++)
            t == 1 ? (last = last->next) : (head = head->prev);

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

    n++;
    while (n--)
        if (arr[n]) free(arr[n]);
    free(arr);
    return 0;
}

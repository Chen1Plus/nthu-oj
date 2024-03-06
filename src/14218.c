#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int idx;
    int killed;
    struct _Node *next;
} Node;

void assign(Node *obj, int idx, int killed, Node *next) {
    obj->idx    = idx;
    obj->killed = killed;
    obj->next   = next;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;

        scanf("%d", &n);
        Node *arr = (Node *)malloc(sizeof(Node) * (n + 1));
        for (int i = 1; i < n; i++) assign(&arr[i], i, 0, &arr[i + 1]);
        assign(&arr[n], n, 0, NULL);

        scanf("%d", &k);
        while (k--) {
            int idx;
            scanf("%d", &idx);
            if (arr[idx].killed == 0 && arr[idx].next != NULL) {
                printf("%d\n", arr[idx].next->idx);
                arr[idx].next->killed = 1;
                arr[idx].next         = arr[idx].next->next;
            } else
                printf("Penguin07 QQ\n");
        }

        free(arr);
    }
}
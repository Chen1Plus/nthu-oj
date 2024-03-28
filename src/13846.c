#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node *small;
    struct Node *big;
} Node;

Node *new_node(int x) {
    Node *node  = (Node *)malloc(sizeof(Node));
    node->num   = x;
    node->small = node->big = NULL;
    return node;
}

int n;
int input[100010];

Node *parse(int l, int r) {
    if (l == r) return new_node(input[l]);

    Node *node = new_node(input[l]);
    int mid    = (l + r) / 2 + 1;

    if (input[l + 1] > input[l]) {
        node->big   = parse(l + 1, mid - 1);
        node->small = parse(mid, r);
    } else {
        node->small = parse(l + 1, mid - 1);
        node->big   = parse(mid, r);
    }

    return node;
}

void print(Node *node) {
    if (node == NULL) return;

    print(node->small);
    print(node->big);
    n ? printf("%d ", node->num) : printf("%d\n", node->num);

    n--;
    free(node);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &input[i]);

    print(parse(0, --n));
}
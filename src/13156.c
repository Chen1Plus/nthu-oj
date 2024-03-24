#include <stdio.h>

#define MAX 200005

typedef struct Node {
    int idx;
    struct Node *left, *right;
} Node;

int pos[MAX];
int arr[MAX];
Node tree[MAX];

int ans, cur;
void judge(Node *root) {
    if (!root || !ans) return;

    judge(root->left);
    if (root->idx != arr[cur++]) ans = 0;
    if (!ans) return;
    judge(root->right);
}

int main() {
    for (int i = 0; i <= MAX; i++) tree[i].idx = i;

    int n, a, b;
    long long root_idx;
    while (~scanf("%lld", &n)) {
        ans = cur = 1;
        root_idx  = (long long)n * (n + 1) / 2;

        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &a, &b);
            root_idx -= a + b;
            tree[i].left  = a ? &tree[a] : NULL;
            tree[i].right = b ? &tree[b] : NULL;
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            arr[i] = a, pos[a] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (!tree[i].left && !tree[i].right) continue;

            if ((tree[i].left && pos[tree[i].left->idx] > pos[tree[i].idx]) ||
                (tree[i].right && pos[tree[i].right->idx] < pos[tree[i].idx])) {
                Node *tmp     = tree[i].left;
                tree[i].left  = tree[i].right;
                tree[i].right = tmp;
            }
        }

        judge(&tree[root_idx]);
        printf("%s\n", ans ? "YES" : "NO");
    }
}
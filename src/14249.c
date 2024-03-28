#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define mod 998244353  // Define a modulo for the beauty calculation.

typedef struct Node {
    int val;               // {0 ~ 9: number, -1: +, -2: -, -3: *}
    struct Node *lc, *rc;  // Left child, right child.
} Node;

// utils
int as_int(char c);
void swap(int a, int b);
// check if two nodes have an ancestor-descendant relationship.
bool check(int a, int b);

Node *build();
int eval(Node *r);

// raw input
int n;
char input_s[505];
// flattened tree (not ordered)
Node *arr[505];

int main() {
    scanf("%d %s", &n, input_s);
    Node *root = build();

    int max_beauty = eval(root);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (!check(i, j)) {
                swap(i, j);
                int ans    = eval(root);
                max_beauty = (ans > max_beauty) ? ans : max_beauty;
                swap(i, j);
            }

    printf("%d\n", max_beauty);
}

int pos;
Node *build() {
    if (pos >= n) return NULL;

    Node *node = (Node *)malloc(sizeof(Node));
    node->val  = as_int(input_s[pos]);
    arr[pos++] = node;

    node->lc = node->rc = NULL;
    if (node->val < 0) {
        node->lc = build();
        node->rc = build();
    }

    return node;
}

int eval(Node *r) {
    if (r->val >= 0) return r->val;

    int lv = eval(r->lc);
    int rv = eval(r->rc);

    if (r->val == -1) return (lv + rv) % mod;
    if (r->val == -2) return (lv - rv + mod) % mod;
    if (r->val == -3) return ((ll)lv * rv) % mod;
    return -1;  //! unreachable
}

bool dfs(Node *now, Node *target) {
    if (!now) return false;
    if (now == target) return true;
    return dfs(now->lc, target) || dfs(now->rc, target);
}
// depends on dfs
bool check(int a, int b) { return dfs(arr[a], arr[b]) || dfs(arr[b], arr[a]); }

int as_int(char c) {
    switch (c) {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        default:  return c - '0';
    }
}

void swap(int a, int b) {
    Node *tmp  = arr[a]->lc;
    arr[a]->lc = arr[b]->lc;
    arr[b]->lc = tmp;

    tmp        = arr[a]->rc;
    arr[a]->rc = arr[b]->rc;
    arr[b]->rc = tmp;

    int tmp2    = arr[a]->val;
    arr[a]->val = arr[b]->val;
    arr[b]->val = tmp2;
}
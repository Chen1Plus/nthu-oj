#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int idx;
    struct Node* b1;
    struct Node* b0;
} Node;

char input[3002];

Node* parse() {
    int c, num = 0;
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        num = num * 10 + c - '0';

    Node* node = (Node*)malloc(sizeof(Node));
    node->idx  = num;
    node->b1   = c == '?' ? parse() : NULL;
    node->b0   = c == '?' ? parse() : NULL;
    return node;
}

int eval(const Node* node) {
    if (node->b1 == NULL) return input[node->idx] - '0';
    return input[node->idx] - '0' ? eval(node->b1) : eval(node->b0);
}

int main() {
    Node* root = parse();
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", input + 1);
        printf("%d\n", eval(root));
    }
}
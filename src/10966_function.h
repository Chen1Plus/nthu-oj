#ifndef FUNCTION_H
#define FUNCTION_H

#include <malloc.h>

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum { ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR } TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* makeNode(char c) {
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    switch (c) {
        case 'A': node->data = ID_A; break;
        case 'B': node->data = ID_B; break;
        case 'C': node->data = ID_C; break;
        case 'D': node->data = ID_D; break;
        case '&': node->data = OP_AND; break;
        case '|': node->data = OP_OR; break;
        default:  break;  // ! unreachable
    }
    node->left = node->right = NULL;
    return node;
}

BTNode* FACTOR();

BTNode* EXPR() {
    BTNode* node = FACTOR();
    if (expr[pos] != '&' && expr[pos] != '|') return node;

    BTNode* root = makeNode(expr[pos--]);
    root->right  = node;
    root->left   = EXPR();
    return root;
}

BTNode* FACTOR() {
    if (expr[pos] >= 'A' && expr[pos] <= 'D') return makeNode(expr[pos--]);

    if (expr[pos] == ')') {
        pos--;
        BTNode* node = EXPR();
        pos--;
        return node;
    }

    // ! unreachable
}

void freeTree(BTNode* root);
void printPrefix(BTNode* root);

#endif
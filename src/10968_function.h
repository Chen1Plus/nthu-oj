#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node **head);
void freeTree(Node *root);

void printInfix(Node *root) {
    if (!root->left && !root->right) {
        printf("%c", root->data);
        return;
    }

    printInfix(root->left);
    printf("%c", root->data);
    if (root->right->data == '|' || root->right->data == '&') {
        printf("(");
        printInfix(root->right);
        printf(")");
    } else
        printInfix(root->right);
}

#endif
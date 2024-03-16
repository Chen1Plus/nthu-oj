#include <stdio.h>
#include <stdlib.h>

#include "10968_function.h"

void constructTree(Node **head) {
    if (!(*head)) {
        (*head)       = (Node *)malloc(sizeof(Node));
        (*head)->data = getchar();
        (*head)->left = (*head)->right = NULL;

        if ((*head)->data == '&' || (*head)->data == '|')
            constructTree(&(*head)->left);
        if ((*head)->data == '&' || (*head)->data == '|')
            constructTree(&(*head)->right);
    }
}

void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);  // the number of test cases

    while (n > 0) {
        getchar();
        Node *root = NULL;
        constructTree(&root);  // construct syntax tree
        printInfix(root);      // you have to implement this function
        printf("\n");
        freeTree(root);
        --n;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000010

typedef struct digit {
    char n;
    struct digit *next;
} Digit;

int main() {
    Digit *head = malloc(sizeof(Digit));
    Digit *cur  = head;

    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') break;
        cur->next = malloc(sizeof(Digit));
        cur       = cur->next;
        cur->n    = c;
    }
    cur->next = NULL;

    int k;
    scanf("%d", &k);
    while (k--) {
        cur = head;
        while (cur->next->n == '0' && cur->next->next != NULL) {
            Digit *tmp = cur->next;
            cur->next  = cur->next->next;
            free(tmp);
        }

        while (cur->next->next != NULL) {
            if (cur->next->n > cur->next->next->n) {
                Digit *tmp = cur->next;
                cur->next  = cur->next->next;
                free(tmp);
                break;
            }
            cur = cur->next;
        }
    }

    cur = head->next;
    while (cur != NULL) {
        printf("%c", cur->n);
        cur = cur->next;
    }
    printf("\n");
}
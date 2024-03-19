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
    Digit *tmp;

    char c;
    while (scanf("%c", &c) != EOF && c != '\n') {
        cur->next = malloc(sizeof(Digit));
        cur       = cur->next;
        cur->n    = c;
    }
    cur->next = NULL;

    int k;
    scanf("%d", &k);
    while (k--) {
        for (cur = head; cur->next->n == '0' && cur->next->next; free(tmp)) {
            tmp       = cur->next;
            cur->next = cur->next->next;
        }

        for (; cur->next->next; cur = cur->next)
            if (cur->next->n > cur->next->next->n) {
                tmp       = cur->next;
                cur->next = cur->next->next;
                break;
            }
        free(tmp);
    }

    for (cur = head->next; cur; cur = cur->next) printf("%c", cur->n);
    printf("\n");
}
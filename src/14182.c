#include <stdio.h>
#include <stdlib.h>

#define MAX 1000010

typedef struct digit {
    char n;
    struct digit *next;
} Digit;

int main() {
    int k;
    Digit *p;
    Digit *head = malloc(sizeof(Digit));
    head->n     = 0;

    p = head;
    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') break;
        p->next    = malloc(sizeof(Digit));
        p->next->n = c;
        p          = p->next;
    }
    p->next = NULL;
    scanf("%d", &k);

    while (k--) {
        p = head;
        while (p->next->n == '0' && p->next->next != NULL)
            p->next = p->next->next;

        while (p->next->next != NULL) {
            if (p->next->n > p->next->next->n) {
                Digit *tmp = p->next;
                p->next    = p->next->next;
                free(tmp);
                break;
            }
            p = p->next;
        }
    }

    p = head->next;
    while (p != NULL) {
        printf("%c", p->n);
        p = p->next;
    }
    printf("\n");
    return 0;
}
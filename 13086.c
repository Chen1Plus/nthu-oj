#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 2010


typedef struct _f_str {
    unsigned long long len;
    struct _f_str *a;
    struct _f_str *b;
    // for f0 and f1 only, otherwise NULL
    char *str;
} f_str;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        unsigned long long k;
        f_str *arr;

        char *a = malloc(sizeof(char) * MAX_STR);
        char *b = malloc(sizeof(char) * MAX_STR);
        scanf("%s %s", a, b);
        scanf("%d %lld", &n, &k);
        arr = malloc(sizeof(f_str) * (n >= 2 ? n + 1 : 2));
        arr[0].len = strlen(a);
        arr[0].str = a;
        arr[0].a = NULL;
        arr[1].len = strlen(b);
        arr[1].str = b;
        arr[1].a = NULL;
        for (int i = 2; i <= n; i++) {
            arr[i].len = arr[i - 1].len + arr[i - 2].len;
            arr[i].a = &arr[i - 2];
            arr[i].b = &arr[i - 1];
            arr[i].str = NULL;
        }

        f_str *cur = &arr[n];
        while (cur->str == NULL && cur->a != NULL)
            if (cur->a->len > k)
                cur = cur->a;
            else {
                k -= cur->a->len;
                cur = cur->b;
            }
        printf("%c\n", cur->str[k]);

        free(arr[0].str);
        free(arr[1].str);
        free(arr);
    }
    return 0;
}
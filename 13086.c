#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 2010
#define MAX_N 60


typedef struct _f_str {
    unsigned long long len;
    struct _f_str *a;
    struct _f_str *b;
    char *str;
} f_str;

int main() {
    int n;
    unsigned long long k;
    f_str *arr = malloc(sizeof(f_str) * MAX_N);
    arr[0].str = malloc(sizeof(char) * MAX_STR);
    arr[1].str = malloc(sizeof(char) * MAX_STR);
    arr[0].a = NULL;
    arr[1].a = NULL;

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", arr[0].str, arr[1].str);
        scanf("%d %lld", &n, &k);
        arr[0].len = strlen(arr[0].str);
        arr[1].len = strlen(arr[1].str);

        for (int i = 2; i <= n; i++) {
            arr[i].len = arr[i - 1].len + arr[i - 2].len;
            arr[i].a = &arr[i - 2];
            arr[i].b = &arr[i - 1];
        }

        f_str *cur = &arr[n];
        while (cur->a != NULL)
            if (cur->a->len > k)
                cur = cur->a;
            else {
                k -= cur->a->len;
                cur = cur->b;
            }

        printf("%c\n", cur->str[k]);
    }

    free(arr[0].str);
    free(arr[1].str);
    free(arr);
    return 0;
}

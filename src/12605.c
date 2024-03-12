#include <stdio.h>
#include <stdlib.h>

int main() {
    char from[26];
    for (int i = 0; i < 26; i++) from[i] = (char)('a' + i);

    int n, m;
    scanf("%d %d", &n, &m);
    char *str = malloc(sizeof(char) * (n + 1));
    scanf("%s", str);

    char *a = malloc(sizeof(char) * m);
    char *b = malloc(sizeof(char) * m);
    for (int i = 0; i < m; i++) scanf(" %c %c", &a[i], &b[i]);

    for (int i = m - 1; i >= 0; i--) {
        char tmp         = from[a[i] - 'a'];
        from[a[i] - 'a'] = from[b[i] - 'a'];
        from[b[i] - 'a'] = tmp;
    }

    for (int i = 0; i < n; i++) printf("%c", from[str[i] - 'a']);
    printf("\n");

    free(str);
    free(a);
    free(b);
}

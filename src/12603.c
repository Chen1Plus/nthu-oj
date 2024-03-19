#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, last, cur, min = INT_MAX;

    scanf("%d", &n);
    char* s = malloc(sizeof(char) * (n + 1));
    scanf("%s %d", s, &last);

    for (int i = 1; i < n; last = cur, i++) {
        scanf("%d", &cur);
        if (s[i] == 'L' && s[i - 1] == 'R' && cur - last < min)
            min = cur - last;
    }

    printf("%d\n", min != INT_MAX ? min / 2 : -1);
}

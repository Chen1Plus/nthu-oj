#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char* s = malloc(sizeof(char) * (n + 1));
    scanf("%s", s);

    int ans = 0;
    int min = INT_MAX;

    int last, cur;
    scanf("%d", &last);
    for (int i = 1; i < n; i++) {
        scanf("%d", &cur);
        if (s[i] == 'L' && s[i - 1] == 'R' && cur - last < min) {
            ans = 1;
            min = cur - last;
        }
        last = cur;
    }

    printf("%d\n", ans ? min / 2 : -1);
}

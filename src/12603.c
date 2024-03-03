#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char* s = malloc(sizeof(char) * (n + 1));
    scanf("%s", s);

    int min = INT_MAX;
    int last, cur;
    scanf("%d", &last);
    for (int i = 1; i < n; i++) {
        scanf("%d", &cur);
        if (s[i] == 'L' && s[i - 1] == 'R' && cur - last < min)
            min = cur - last;
        last = cur;
    }

    printf("%d\n", min != INT_MAX ? min / 2 : -1);
}

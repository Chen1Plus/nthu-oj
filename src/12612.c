#include <stdio.h>
#include <string.h>

int main() {
    char tmp[10010];
    char s[10010];
    scanf("%s", s);

    int n;
    scanf("%d", &n);
    int l, r, k;
    while (n--) {
        scanf("%d %d %d", &l, &r, &k);
        k %= r - l + 1;

        strncpy(tmp, s + l - 1, r - l + 1);
        strncpy(s + l - 1 + k, tmp, r - l + 1 - k);
        strncpy(s + l - 1, tmp + r - l + 1 - k, k);
    }

    printf("%s\n", s);
}
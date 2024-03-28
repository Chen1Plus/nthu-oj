#include <stdio.h>

int seafu[1010];
int disciples[1010];

int is_seafu(int s, int d) {
    for (; d; d = seafu[d])
        if (d == s) return 1;
    return 0;
}

int main() {
    int n, q, m, a, b;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) scanf("%d", &seafu[i]);
    for (; n; n--) disciples[seafu[n]] += disciples[n] + 1;

    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &m, &a);
        switch (m) {
            case 1: printf("%d\n", disciples[a]); break;
            case 2:
                scanf("%d", &b);
                printf("%d\n", is_seafu(a, b) ? 1 : is_seafu(b, a) ? 0 : -1);
                break;
        }
    }
}
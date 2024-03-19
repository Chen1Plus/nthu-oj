#include <stdio.h>

int main() {
    int game[1010];
    int n, m, bill, ans, i;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &game[i]);
    scanf("%d", &bill);

    for (i = ans = 0; i < n; i++)
        if (bill >= game[i]) {
            ans++, m--;
            if (!m) break;
            scanf("%d", &bill);
        }

    printf("%d\n", ans);
}
#include <stdio.h>

int main() {
    int game[1010];
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &game[i]);

    int bill;
    scanf("%d", &bill);
    m--;

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (bill >= game[i]) {
            ans++;
            if (m == 0) break;
            scanf("%d", &bill);
            m--;
        }

    printf("%d\n", ans);
}
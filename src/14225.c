#include <stdio.h>

int student[1001];
int distance[1001];

int main() {
    int n, i, iter = 1;
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        scanf("%d", &student[i]);
        distance[i] = student[i] == 1;
    }

    while (iter)
        for (i = 2, iter = 0; i <= n; i++) {
            if (distance[i]) continue;
            if (distance[student[i]]) distance[i] = distance[student[i]] + 1;
            iter++;
        }
    for (i = 2; i < n; i++) printf("%d ", distance[i]);
    printf("%d\n", distance[n]);

    int q, a, b, ans;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &a, &b);
        for (ans = student[a], b--; b && ans; b--) ans = student[ans];
        printf("%d\n", ans ? ans : -1);
    }
}
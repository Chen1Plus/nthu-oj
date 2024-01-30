// refer to online solutions

#include <stdio.h>

long long len[55];
long long id;

void solve(int k, int l, int r) {
    if (k == 0 || id > r) return;

    if (id >= l && id <= r) printf("O");
    if (++id > r) return;

    id + len[k - 1] < l ? id += len[k - 1] : solve(k - 1, l, r);

    if (id >= l && id <= r) printf("u");
    if (++id > r) return;

    id + len[k - 1] < l ? id += len[k - 1] : solve(k - 1, l, r);

    if (id >= l && id <= r) printf("Q");
    id++;
}

int main() {
    for (int i = 1; i <= 50; i++) len[i] = 3 + 2 * len[i - 1];

    int k, l, r;
    while (scanf("%d %d %d", &k, &l, &r) != EOF) {
        id = 0;
        solve(k, l, r);
        printf("\n");
    }
}
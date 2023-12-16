#include <stdbool.h>
#include <stdio.h>

int n, m;
bool board[16];

void flip(int x) {
    board[x] = !board[x];
    if (x % m != 0) board[x - 1] = !board[x - 1];
    if (x % m != m - 1) board[x + 1] = !board[x + 1];
    if (x >= m) board[x - m] = !board[x - m];
    if (x < n * m - m) board[x + m] = !board[x + m];
}

// return -1 if impossible, otherwise return the number of flips
int recur(int x, int cnt) {
    if (x == n * m) {
        bool ans = board[0];
        for (int i = 1; i < n * m; i++)
            if (board[i] != ans) return -1;
        return cnt;
    }

    int tmp = recur(x + 1, cnt);
    flip(x);
    int tmp2 = recur(x + 1, cnt + 1);
    flip(x);

    return tmp == -1 ? tmp2 : (tmp2 == -1 ? tmp : (tmp < tmp2 ? tmp : tmp2));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n * m; i++) {
            getchar();
            board[i] = getchar() == 'w';
        }
        int ans = recur(0, 0);
        printf((ans == -1 ? "oops\n" : "%d\n"), ans);
    }
    return 0;
}

#include <stdio.h>

const char *s = "ICPCASIASG";

const int move[8][2] = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2},
                        {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};

int n;
int cur;
char board[110][110];

int solve(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int x1 = x + move[i][0], y1 = y + move[i][1];
        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) continue;
        if (board[x1][y1] == s[cur + 1]) {
            cur++;
            if (cur == 9) return 1;
            if (solve(x1, y1)) return 1;
            cur--;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf(" %c", &board[i][j]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 'I') {
                cur = 0;
                if (solve(i, j)) {
                    ans = 1;
                    break;
                }
            }

    printf("%s\n", ans ? "YES" : "NO");
}
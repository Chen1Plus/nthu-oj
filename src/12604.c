#include <stdio.h>

int n, m, board_size;
char board[9][9];

int solutions;

// mode: 0 queen, 1 rook
int check(int row, int col, int mode) {
    for (int i = row - 1; i >= 0; i--)
        if (board[i][col] != '0') return 0;

    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') return 0;
        if (board[i][j] == 'R' && mode == 0) return 0;
        i--;
        j--;
    }

    i = row - 1, j = col + 1;
    while (i >= 0 && j < board_size) {
        if (board[i][j] == 'Q') return 0;
        if (board[i][j] == 'R' && mode == 0) return 0;
        i--;
        j++;
    }

    return 1;
}

void place(int line) {
    if (line == board_size) {
        solutions++;
        return;
    }

    for (int i = 0; i < board_size; i++) {
        if (check(line, i, 0) && n > 0) {
            n--;
            board[line][i] = 'Q';
            place(line + 1);
            n++;
            board[line][i] = '0';
        }

        if (check(line, i, 1) && m > 0) {
            m--;
            board[line][i] = 'R';
            place(line + 1);
            m++;
            board[line][i] = '0';
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        solutions  = 0;
        board_size = n + m;
        for (int i = 0; i < board_size; i++)
            for (int j = 0; j < board_size; j++) board[i][j] = '0';

        place(0);
        printf("%d\n", solutions);
    }
}

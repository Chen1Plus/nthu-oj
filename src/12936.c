#include <stdbool.h>
#include <stdio.h>

char board[50][50];

void scan_arr(int arr[][50], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i][0]);
        for (int j = 1; j <= arr[i][0]; j++) scanf("%d", &arr[i][j]);
    }
}

bool check(int rows, int cols, int colors[][50], int mode) {
    for (int i = 0; i < rows; i++) {
        int valid_num = 0;
        int cnt;
        bool counting = false;

        for (int j = 0; j < cols; j++) {
            const bool is_o = (mode == 0 ? board[i][j] : board[j][i]) == 'o';

            if (!counting && is_o) {
                counting = true;
                cnt = 1;
            } else if (counting) {
                if (is_o)
                    cnt++;
                else {
                    if (cnt != colors[i][++valid_num]) return false;
                    counting = false;
                }
            }
        }

        if (counting)
            if (cnt != colors[i][++valid_num]) return false;
        if (valid_num != colors[i][0]) return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);

    int rows, cols;
    int row_colors[50][50];
    int col_colors[50][50];

    while (t--) {
        scanf("%d %d", &rows, &cols);
        scan_arr(row_colors, rows);
        scan_arr(col_colors, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) scanf(" %c", &board[i][j]);

        printf((check(rows, cols, row_colors, 0) &&
                check(cols, rows, col_colors, 1))
                   ? "Yes\n"
                   : "No\n");
    }
    return 0;
}
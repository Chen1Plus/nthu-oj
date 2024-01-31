#include <stdio.h>

int is_leap(int y) { return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0; }

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        int target = n;
        int acc    = 0;
        do {
            acc += is_leap(target) ? 2 : 1;
            target++;
        } while (acc % 7 != 0 || is_leap(target) != is_leap(n));

        printf("%d\n", target);
    }
}
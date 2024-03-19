#include <stdio.h>

int main() {
    unsigned long long money = 0;
    int days, last, current;

    scanf("%d %d", &days, &last);
    for (int i = 1; i < days; i++, last = current) {
        scanf("%d", &current);
        if (current > last) money += current - last;
    }

    printf("%llu\n", money);
}
#include <stdio.h>

int main() {
    unsigned long long money = 0;
    int last, current;

    int days;
    scanf("%d", &days);
    scanf("%d", &last);
    for (int i = 1; i < days; i++) {
        scanf("%d", &current);
        if (current > last) money += current - last;
        last = current;
    }

    printf("%llu\n", money);
    return 0;
}
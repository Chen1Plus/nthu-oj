#include <limits.h>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int bob, min = INT_MAX, max = -1;
    scanf("%d", &bob);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (x > max) max = x;
        if (x < min) min = x;
    }

    int distance;
    if (bob > max)
        distance = bob - min;
    else if (bob < min)
        distance = max - bob;
    else
        distance = max - min;

    printf("%d\n", distance * 2);
}
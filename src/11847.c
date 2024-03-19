#include <stdio.h>

int cur, a, b, c, d;
char str[30];

int parse() {
    switch (str[cur++]) {
        case 'A': return a;
        case 'B': return b;
        case 'C': return c;
        case 'D': return d;
        case '&': return parse() & parse();
        case '|': return parse() | parse();
    }
}

int main() {
    scanf("%s", str);

    for (a = 0; a < 2; a++)
        for (b = 0; b < 2; b++)
            for (c = 0; c < 2; c++)
                for (d = 0; d < 2; d++) {
                    cur = 0;
                    printf("%d %d %d %d %d\n", a, b, c, d, parse());
                }
}
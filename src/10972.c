#include <stdio.h>

#define is_paren_l(pos) (str[(pos)] == '(')
#define is_paren_r(pos) (str[(pos)] == ')')

#define print_c printf("%c", str[pos++])

int pos;
char str[256];

int not_single(int cur) {
    int cnt = 0;
    while (is_paren_l(cur++)) cnt++;
    while (cnt && is_paren_r(cur++)) cnt--;
    return cnt;
}

void expr() {
    int suffix = 0;

    if (str[pos] >= 'A' && str[pos] <= 'D')
        print_c;  // A|B|C|D
    else if (is_paren_l(pos)) {
        pos++;
        expr();
        is_paren_r(pos) ? pos++ : suffix++;
    }

    while (str[pos] == '&' || str[pos] == '|') {
        print_c;  // op
        if (is_paren_l(pos) && not_single(pos)) {
            print_c;  // '('
            expr();
            print_c;  // ')'
        } else
            expr();
    }

    pos += suffix;
}

int main() {
    scanf("%s", &str);
    expr();
}

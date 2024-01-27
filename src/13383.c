#include <stdio.h>
#include <string.h>

#define CARD_NUM 10

typedef struct {
    enum { ALL, NO, NUMS } type;
    int value;
    int len;
    short arr[10000];
} Cards;

Cards cards[CARD_NUM];

void print() {
    for (int i = 0; i < CARD_NUM; i++) {
        Cards e = cards[i];
        printf("%d:", i);
        switch (e.type) {
            case NO: printf(" No card"); break;
            case ALL:
                for (int j = 0; j < e.len; ++j) printf(" %d", e.value);
                break;
            case NUMS:
                for (int j = 0; j < e.len; ++j) printf(" %d", e.arr[j]);
                break;
        }
        printf("\n");
    }
}

void all() {
    short num, len;
    scanf("%hd %hd", &num, &len);

    for (int i = 0; i < CARD_NUM; i++) {
        cards[i].type  = ALL;
        cards[i].len   = len;
        cards[i].value = num;
    }
}

void place() {
    int card_idx, len;
    scanf("%d %d", &card_idx, &len);

    cards[card_idx].type = NUMS;
    cards[card_idx].len  = len;
    for (int i = 0; i < len; i++) scanf("%hd", &cards[card_idx].arr[i]);
}

void clear() {
    for (int i = 0; i < CARD_NUM; ++i) cards[i].type = NO;
}

void swap(int a_idx, int b_idx) {
    Cards tmp    = cards[a_idx];
    cards[a_idx] = cards[b_idx];
    cards[b_idx] = tmp;
}

int main() {
    for (int i = 0; i < CARD_NUM; ++i) cards[i].type = NO;

    char cmd[15];
    while (scanf("%s", cmd) != EOF && strcmp(cmd, "exit") != 0) {
        if (strcmp(cmd, "print") == 0)
            print();
        else if (strcmp(cmd, "all") == 0)
            all();
        else if (strcmp(cmd, "place") == 0)
            place();
        else if (strcmp(cmd, "clear") == 0)
            clear();
        else if (strcmp(cmd, "swap") == 0) {
            int a_idx, b_idx;
            scanf("%d %d", &a_idx, &b_idx);
            swap(a_idx, b_idx);
        } else if (strcmp(cmd, "shiftleft") == 0)
            for (int i = 9; i > 0; i--) swap(i, 0);
        else if (strcmp(cmd, "shiftright") == 0)
            for (int i = 0; i < 9; i++) swap(i, 9);
    }
    return 0;
}
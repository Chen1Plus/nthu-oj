#include <stdio.h>
#include <string.h>

#define CARD_NUM 10

typedef struct {
    enum { ALL, NO, NUMS } type;
    short value;
    short len;
    short arr[10000];
} Cards;

Cards cards[CARD_NUM];

void print() {
    for (int i = 0; i < CARD_NUM; i++) {
        Cards *e = &cards[i];
        printf("%d:", i);
        switch ((*e).type) {
            case NO:
                printf(" No card");
                break;
            case ALL:
                for (int j = 0; j < (*e).len; ++j) printf(" %d", (*e).value);
                break;
            case NUMS:
                for (int j = 0; j < (*e).len; ++j) printf(" %d", (*e).arr[j]);
                break;
        }
        printf("\n");
    }
}

void all() {
    short num, len;
    scanf("%hd %hd", &num, &len);

    for (int i = 0; i < CARD_NUM; i++) {
        cards[i].type = ALL;
        cards[i].len = len;
        cards[i].value = num;
    }
}

void place() {
    short card_idx, len;
    scanf("%hd %hd", &card_idx, &len);

    cards[card_idx].type = NUMS;
    cards[card_idx].len = len;
    for (int i = 0; i < len; i++) scanf("%hd", &cards[card_idx].arr[i]);
}

void clear() {
    for (int i = 0; i < CARD_NUM; ++i) cards[i].type = NO;
}

void swap() {
    short a_idx, b_idx;
    scanf("%hd %hd", &a_idx, &b_idx);

    Cards tmp = cards[a_idx];
    cards[a_idx] = cards[b_idx];
    cards[b_idx] = tmp;
}

int main() {
    for (int i = 0; i < CARD_NUM; ++i) cards[i].type = NO;

    char cmd[6];
    while (scanf("%s", cmd) != EOF && strcmp(cmd, "exit") != 0) {
        if (strcmp(cmd, "print") == 0)
            print();
        else if (strcmp(cmd, "all") == 0)
            all();
        else if (strcmp(cmd, "place") == 0)
            place();
        else if (strcmp(cmd, "clear") == 0)
            clear();
        else if (strcmp(cmd, "swap") == 0)
            swap();
    }
    return 0;
}
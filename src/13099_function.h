#include <stdlib.h>

#define MAX_NAME 100

typedef struct _Item {
    char* name;
    int price;
    int discount;
    int quality;
} Item;

Item* CreateList(int N) {
    Item* L = malloc(sizeof(Item) * N);
    return L;
}

void AddItem(Item* L, int idx, char* name, int price, int discount,
             int quality) {
    L[idx].name = malloc(sizeof(char) * (MAX_NAME + 1));
    strncpy(L[idx].name, name, MAX_NAME + 1);
    L[idx].price    = price;
    L[idx].discount = discount;
    L[idx].quality  = quality;
}

void DeleteList(Item* L, int N) {
    for (int i = 0; i < N; i++) free(L[i].name);
    free(L);
}

int price_cmp(const void* lhs, const void* rhs) {
    Item *l = (Item*)lhs, *r = (Item*)rhs;
    return (l->price - l->discount) - (r->price - r->discount);
}

int discount_cmp(const void* lhs, const void* rhs) {
    return ((Item*)rhs)->discount - ((Item*)lhs)->discount;
}

int quality_cmp(const void* lhs, const void* rhs) {
    return ((Item*)rhs)->quality - ((Item*)lhs)->quality;
}
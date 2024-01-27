#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10005

typedef struct {
    char name[35];
    // order meaningful
    enum {
        ELDER,
        NURSY,
        KITTY,
        WARRIOR,
        APPRENTICE,
        MEDICENT,
        DEPUTY,
        LEADER
    } job;
    int age;
} Cat;

int cat_cmp(const void* a, const void* b) {
    Cat* ca = (Cat*)a;
    Cat* cb = (Cat*)b;

    if (ca->job != cb->job) return ca->job - cb->job;
    if (ca->age != cb->age)
        return (ca->age - cb->age) * (ca->job == APPRENTICE ? 1 : -1);
    return strcasecmp(ca->name, cb->name);
}

int main() {
    int n, m;
    Cat* cats = malloc(sizeof(Cat) * MAXN);
    while (scanf("%d %d", &n, &m) != EOF) {
        // input
        char tmp[15];
        for (int i = 0; i < n; i++) {
            scanf("%s %s %d", cats[i].name, tmp, &cats[i].age);
            switch (tmp[0]) {
                case 'e': cats[i].job = ELDER; break;
                case 'n': cats[i].job = NURSY; break;
                case 'k': cats[i].job = KITTY; break;
                case 'w': cats[i].job = WARRIOR; break;
                case 'a': cats[i].job = APPRENTICE; break;
                case 'm': cats[i].job = MEDICENT; break;
                case 'd': cats[i].job = DEPUTY; break;
                case 'l': cats[i].job = LEADER; break;
            }
        }
        // sort
        qsort(cats, n, sizeof(Cat), cat_cmp);
        // output
        for (int i = 0; i < m && i < n; i++) printf("%s\n", cats[i].name);
    }
    free(cats);
    return 0;
}
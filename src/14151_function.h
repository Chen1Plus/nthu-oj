#include <stdlib.h>

typedef struct {
    char *guestName;
    int groupSize;
    int arriveTime;
    int diningTime;
} Guest;

typedef struct {
    int tableSize;
    int leaveTime;
    Guest *guest;
} Table;

Table *createTable() {
    Table *table = malloc(sizeof(Table));
    scanf("%d", &table->tableSize);
    table->guest     = NULL;
    table->leaveTime = 0;
    return table;
}

Guest *createGuest() {
    Guest *guest     = malloc(sizeof(Guest));
    guest->guestName = malloc(sizeof(char) * 15);
    scanf("%s %d %d %d", guest->guestName, &guest->groupSize,
          &guest->arriveTime, &guest->diningTime);
    return guest;
}

Guest *checkLeave(Table **table, int tableCount, int currentTime) {
    for (int i = 0; i < tableCount; i++)
        if (table[i]->leaveTime == currentTime) {
            Guest *leave        = table[i]->guest;
            table[i]->guest     = NULL;
            table[i]->leaveTime = 0;
            return leave;
        }
    return NULL;
}

int assignTable(Table **table, int tableCount, int currentTime, Guest *guest) {
    for (int i = 0; i < tableCount; i++)
        if (table[i]->guest == NULL &&
            table[i]->tableSize >= guest->groupSize) {
            table[i]->guest     = guest;
            table[i]->leaveTime = currentTime + guest->diningTime;
            return 1;
        }
    return 0;
}

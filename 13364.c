#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FOLDER_CNT 100

int main() {
    char o_path[5001];
    char d_path[5001];
    char **folder = malloc(sizeof(char *) * MAX_FOLDER_CNT);
    bool used_folder[MAX_FOLDER_CNT];

    int t;
    scanf("%d", &t);
    while (t--) {
        int used_cnt = 0;
        int folder_cnt = 0;
        for (int i = 0; i < MAX_FOLDER_CNT; i++) used_folder[i] = false;
        scanf("%s %s", o_path, d_path);

        char *token = strtok(d_path, "/");
        while (token != NULL) {
            folder[folder_cnt++] = token;
            token = strtok(NULL, "/");
        }

        token = strtok(o_path, "/");
        while (token != NULL) {
            int idx = -1;
            for (int i = 0; i < folder_cnt; i++)
                if (!used_folder[i] && strcmp(token, folder[i]) == 0) {
                    used_folder[i] = true;
                    idx = i;
                    break;
                }

            if (idx == -1) break;
            used_cnt++;
            token = strtok(NULL, "/");
        }

        printf("%svalid\n", used_cnt == folder_cnt ? "" : "not ");
    }
    return 0;
}
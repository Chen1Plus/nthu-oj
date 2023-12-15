#include <stdio.h>
#include <string.h>

int main() {
    int link_num = 0;
    char input[1001];
    enum { NONE, HEAD, BODY } possition = NONE;

    while (fgets(input, 1000, stdin) != NULL) {
        if (strstr(input, "<head>") != NULL)
            possition = HEAD;
        else if (strstr(input, "<body>") != NULL)
            possition = BODY;
        else if (strstr(input, "</head>") != NULL ||
                 strstr(input, "</body>") != NULL)
            possition = NONE;

        if (possition == HEAD) {
            char *title = strstr(input, "<title>");
            if (title != NULL) {
                title += 7;
                int title_len = 0;

                while (strncmp(title + title_len, "</title>", 7) != 0)
                    title_len++;
                title[title_len] = '\0';

                printf("%s\n", title);
            }
        } else if (possition == BODY) {
            int cursor = 0;
            while (input[cursor] != '\0') {
                if (strncmp(input + cursor, "</a>", 4) == 0) link_num++;
                cursor++;
            }
        }
    }

    printf("%d\n", link_num);
    return 0;
}
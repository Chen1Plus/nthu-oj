#include <stdio.h>
#include <string.h>

int main() {
    int link_num = 0;
    char input[1001];
    enum { NONE, HEAD, BODY } position = NONE;

    while (fgets(input, 1000, stdin)) {
        position = strstr(input, "<head>")   ? HEAD
                   : strstr(input, "<body>") ? BODY
                   : (strstr(input, "</head>") || strstr(input, "</body>"))
                       ? NONE
                       : position;

        if (position == HEAD) {
            char *title = strstr(input, "<title>");
            if (title != NULL) {
                title += 7;
                int title_len = 0;

                while (strncmp(title + title_len, "</title>", 7) != 0)
                    title_len++;
                title[title_len] = '\0';

                printf("%s\n", title);
            }
        } else if (position == BODY)
            for (int cursor = 0; input[cursor]; cursor++)
                if (strncmp(input + cursor, "</a>", 4) == 0) link_num++;
    }

    printf("%d\n", link_num);
}
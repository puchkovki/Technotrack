// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* strtok_(char* string, const char* delim);
int strchr_(const char* delim, char ch);

int main(void) {
    char str[] = "This is - www.tutorialspoint.com - website.";
    char* pch = strtok_(str, " ");  // второй параметр — разделители

    while (pch != NULL) {  // пока есть лексемы
        if (pch != "\0") {
            printf("%s\n", pch);
        }
        free(pch);
        pch = strtok_(NULL, " ");
    }

    printf("\n");
    char str1[] = "This is - www.tutorialspoint.com - website.";
    char* pch1 = strtok(str1, " ");  // второй параметр — разделители

    while (pch1 != NULL) {  // пока есть лексемы
        printf("%s\n", pch1);
        pch1 = strtok(NULL, " ");
    }

    return EXIT_SUCCESS;
}

char* strtok_(char* string, const char* delim) {
    static char* pointer;  // старая строка, когда передадим NULL
    if (string == NULL) {  // не первый запуск, значит считываем значение
        string = pointer;  // с предыдущей операции
    }

    int cnt = -1;
    for (int i = 0; string[i] != '\0'; ++i) {
        if (strchr_(delim, string[i]) != -1) {  // символ не разделитель
            cnt = i;
            break;
        }
    }

    char* tmp;
    if (cnt == -1) {  // не нашли совпадений, заканчиваем поиски
        printf("%s\n", string);
        free(tmp);  // не забываем освободить память
        return NULL;
    }

    tmp = (char*) calloc(cnt + 1, sizeof(char));
    for (int i = 0; i < cnt; ++i) {
        tmp[i] = string[i];
    }
    tmp[cnt] = '\0';

    pointer = string + cnt + 1;
    return tmp;
}

int strchr_(const char* delim, char ch) {
    for (int i = 0; delim[i] != '\0'; ++i) {
        if (delim[i] == ch) {
            return i;
        }
    }

    return -1;
}

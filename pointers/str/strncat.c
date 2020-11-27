// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* strncat_(char* destptr, const char* srcptr, size_t count);

int main(void) {
    char str[] = "Hi, I'm testing strcpy! I hope it will work";  // создаем буфер
    char s_1[80] = {"Hello, "};
    char temp_1[80] = {"Hello, "};

    strncat_(s_1, str, 12);
    printf("You've written in s_1 '%s'.\nLength of this string is %ld.\n", s_1,
        strlen(s_1));  // выводим строку и количество символов в ней
    if (!strcmp(s_1, strncat(temp_1, str, 12))) {
        printf("1. Ok!\n");
    } else {
        printf("1. Failed!\n");
    }
    return EXIT_SUCCESS;
}

char* strncat_(char* dest, const char* src, size_t num) {
    int min = num;
    size_t src_size = strlen(src);
    size_t dest_size = strlen(dest);
    if (src_size < min) {
        min = src_size;
    }

    for (int i = 0; i < min; i++) {
        dest[i + dest_size] = src[i];
    }

    dest[min + dest_size] = '\0';
    return dest;
}

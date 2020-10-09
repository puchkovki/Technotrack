// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* strncpy_(char* destptr, const char* srcptr, size_t num);

int main(void) {
    char str[] = "Hi, I'm f.cking stuck! Why it's always me?";  // создаем буфер

    /*char s_1[1];
    char temp_1[1];*/

    char s_2[42];
    char temp_2[42];

    char s_3[80];
    char temp_3[80];

    /*sleep(1);
    strncpy_(s_1, str, 2);
    printf("You've written in s_1 '%s'.\nLength of this string is %ld.\n", s_1,
        strlen(s_1));  // выводим строку и количество символов в ней
    if (!strcmp(s_1, strncpy_(temp_1, str, 2))) {
        printf("1. Ok!\n");
    } else {
        printf("1. Failed!\n");
    }*/

    strncpy_(s_2, str, 41);
    printf("You've written in s_2 '%s'.\nLength of this string is %ld.\n", s_2,
        strlen(s_2));  // выводим строку и количество символов в ней
    if (!strcmp(s_2, strncpy(temp_2, str, 41))) {
        printf("2. Ok!\n");
    } else {
        printf("2. Failed!\n");
    }

    strncpy_(s_3, str, 80);
    printf("You've written in s_3 '%s'.\nLength of this string is %ld.\n", s_3,
        strlen(s_3));  // выводим строку и количество символов в ней
    if (!strcmp(s_3, strncpy(temp_3, str, 80))) {
        printf("3. Ok!\n");
    } else {
        printf("3. Failed!\n");
    }
    return EXIT_SUCCESS;
}

char* strncpy_(char* destptr, const char* srcptr, size_t num) {
    int min = num;
    size_t srcptr_size = strlen(srcptr);

    if (srcptr_size < min) {
        min = srcptr_size;
    }

    for (int i = 0; i < min; i++) {
        destptr[i] = srcptr[i];
    }
    destptr[min] = '\0';
    return destptr;
}

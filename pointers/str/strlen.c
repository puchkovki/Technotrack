// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int strlen_(char* str);

int main(void) {
    char str[] = "Hi, I'm testing strcpy! I hope it will work";  // создаем буфер
    int string_length = strlen_(str);  // длина строки

    sleep(1);
    printf("You've written string '%s'.\nLength of this string is %d.\n", str,
        string_length);  // выводим строку и количество символов в ней

    if (string_length == strlen(str)) {
        printf("Ok!\n");
    } else {
        printf("Failed!\n");
    }

    return EXIT_SUCCESS;
}

int strlen_(char* str) {
    int string_length = 0;  // изначальная длина любой строки - 0

    while (*str != '\0') {
        string_length++;
        str++;
    }

    return string_length;  // возвращаем указатель на считанную строку
}

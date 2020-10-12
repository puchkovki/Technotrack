// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>

int input(char** str);

int main(void) {
    char* str = (char*) calloc(1, sizeof(char));  // создаем динамический буфер
    if (str == NULL) {
        fprintf(stderr, "input: cannot allocate memory\n");
        return EXIT_FAILURE;
    }
    int string_length = input(&str);  // длина строки
    fprintf(stderr, "input: ok!\n");

    printf("You've written string '%s'.\nLength of this string is %d.\n", str,
        string_length);  // выводим строку и количество символов в ней

    free(str);  // освобождаем динамическую память
    return EXIT_SUCCESS;
}

int input(char** str) {
    int string_length = 0;  // изачальная длина любой строки - 0
    int capasity = 1;  // вместительность строки (1, т.к. точно будет \0)

    char c = getchar();  // считываем первый символ
    while (c != '\n') {
        (*str)[string_length] = c;  // не символ переноса можно записывать
        string_length++;  // увеличиваем индекс последнего эелемента буфера

        if (string_length >= capasity) {  // если размер стал равным
                                          // вместимости
            capasity *= 2;  // увеличиваем вместимость дважды
            (*str) = (char*) realloc(*str, capasity * sizeof(char));  // увеличиваем буфер
            if (*str == NULL) {
                printf("input: cannot reallocate the memory\n");
                return -1;
            }
        }

        c = getchar();  // считываем следующий символ для проверки
    }
    (*str)[string_length] = '\0';  // правильно завершаем строку

    return string_length;  // возвращаем число считанных символов
}

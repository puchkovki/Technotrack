// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>

char* input(int* string_length);

int main(void) {
    int string_length;  // длина строки
    char* str = input(&string_length);  // вводим строку

    printf("You've written string '%s'.\nLength of this string is %d.\n", str,
        string_length);  // выводим строку и количество символов в ней

    free(str);  // освобождаем динамическую память
    return EXIT_SUCCESS;
}

char* input(int* string_length) {
    *string_length = 0;  // изачальная длина пустой строки - 0
    int capasity = 1;  // вместительность строки = 1, т.к. точно будет \0
    char* s = (char*) calloc(capasity, sizeof(char));  // создаем динамический буфер
    if (s == NULL) {
        fprintf(stderr, "input: cannot allocate memory\n");
        return NULL;
    }

    char c = getchar();  // считываем первый символ
    while (c != '\n') {  // если не символ переноса, то строка не закончена
        s[*string_length] = c;
        (*string_length)++;

        if (*string_length >= capasity) {  // если размер стал равным
                                        // вместимости
            capasity *= 2;  // увеличиваем вместимость на порядок
            s = (char*)realloc(s, capasity * sizeof(char)); // увеличиваем буфер
            if (s == NULL) {
                printf("input: cannot reallocate the memory\n");
            }
        }
        c = getchar();  // считываем символ для проверки
    }
    s[*string_length] = '\0';  // правильно завершаем строку
    
    return s;  // возвращаем указатель на считанную строку
}

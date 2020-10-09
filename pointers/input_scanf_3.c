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
    *string_length = 0;  // изачальная длина любой строки - 0
    int capacity = 256;  // вместительность строки

    char* s = (char*) malloc(capacity * sizeof(char));

    if (s == NULL) {
        fprintf(stderr, "input: cannot allocate memory\n");
        return NULL;
    }

    int num = 0;
    // читаем по 128 либо пока не встретим '\n' или '\r'
    // в конце получиаем число считанных символов
    while ((scanf("%128[^\n\r]%n", s + *string_length, &num)) > 0) {
        *string_length += num;

        if (*string_length >= capacity / 2) {  // если оптимизация вмешается
            capacity *= 2;  // увеличиваем вместимость на порядок
            s = (char*) realloc(s, capacity * sizeof(char));  // увеличиваем буфер
            if (s == NULL) {
                fprintf(stderr, "input: cannot reallocate memory\n");
                return NULL;
            }
        }
    }

    s[*string_length] = '\0';  // правильно завершаем строку
    return s;  // возвращаем указатель на считанную строку
}

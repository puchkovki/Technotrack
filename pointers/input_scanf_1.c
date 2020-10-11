// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>

int input(char** str);

int main(void) {
    char* str = (char*) calloc(256, sizeof(char));  // создаем динамический буфер
    if (str == NULL) {
        fprintf(stderr, "input: cannot allocate memory\n");
        return EXIT_FAILURE;
    }
    int string_length = input(&str);  // длина строки
    fprintf(stderr, "input: ok!\n");

    printf("You've written string '%s'.\nLength of this string is %d.\n",
        str, string_length);  // выводим строку и количество символов в ней

    free(str);  // освобождаем динамическую память
    return EXIT_SUCCESS;
}

int input(char** str) {
    int string_length = 0;  // изачальная длина любой строки - 0
    int capacity = 256;  // вместительность строки

    int num = 0;
    // читаем по 128 либо пока не встретим \n или \r
    // в конце получиаем число считанных символов
    while ((scanf("%128[^\n\r]%n", *str + string_length, &num)) > 0) {
        string_length += num;
    
        if (string_length >= capacity / 2) {  // если оптимизация вмешается
            capacity *= 2;  // увеличиваем вместимость дважды
            *str = (char*) realloc(*str, capacity * sizeof(char));  // увеличиваем буфер
            if (*str == NULL) {
                fprintf(stderr, "input: cannot reallocate memory\n");
                return -1;
            }
        }
    }
    
    (*str)[string_length] = '\0';  // правильно завершаем строку
    return string_length;  // возвращаем число считанных символов
}

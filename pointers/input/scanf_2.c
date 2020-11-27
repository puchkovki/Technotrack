// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char* input(FILE* fm, const int* string_length);

int main(void) {
    FILE* shakespeare;
    shakespeare = fopen("./text.txt", "r+");
    // Проверка открытия файла
    if (shakespeare == NULL) {
        fprintf(stderr, "fopen: cannot open file\n");
        return EXIT_FAILURE;
    }

    if (fseek(shakespeare, 0, SEEK_END) != 0) {
        fprintf(stderr, "fseek: failed!\n");
    }
    const int string_length = ftell(shakespeare);  // длина строки
    if (fseek(shakespeare, 0, SEEK_SET) != 0) {
        fprintf(stderr, "fseek: failed!\n");
    }

    char* str = input(shakespeare, &string_length);  // вводим строку

    printf("You've written string '%s'.\nLength of this string is %d.\n", str,
        string_length);  // выводим строку и количество символов в ней

    free(str);  // освобождаем динамическую память
    return EXIT_SUCCESS;
}

char* input(FILE* fm, const int* string_length) {
    static char* s;
    s = (char*) calloc(*string_length + 1, sizeof(char));
    fgets(s, *string_length, fm);

    s[*string_length] = '\0';  // правильно завершаем строку
    return s;  // возвращаем указатель на считанную строку
}

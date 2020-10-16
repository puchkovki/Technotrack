// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>

char* input(FILE* shakespeare, int* string_length);

int main(void) {
    FILE* shakespeare;
    shakespeare = fopen("./shakespeare.txt", "r+");
    // Проверка открытия файла
    if (shakespeare == NULL) {
        fprintf(stderr, "fopen: cannot open file\n");
        return EXIT_FAILURE;
    }

    if (fseek(shakespeare, 0, SEEK_END) != 0) {
        fprintf(stderr, "fseek: failed!\n");
    }
    int file_length = ftell(shakespeare);  // размер файла
    printf("%d\n", file_length);

    int string_length = 0;  // длина строки
    int new_string_position = 0;  // откуда начинается следующая строка
    while (new_string_position < file_length) {
        if (fseek(shakespeare, new_string_position, SEEK_SET) != 0) {
            fprintf(stderr, "fseek: failed!\n");
        }
        char* str = input(shakespeare, &string_length);  // вводим строку
        printf("You've written string '%s'.\nLength of this string is %d.\n",
            str, string_length);  // выводим строку и количество символов в ней
        new_string_position += string_length + 1;
        free(str);  // освобождаем динамическую память
    }
    printf("%d\n", new_string_position);

    if (fclose(shakespeare) == EOF) {
        fprintf(stderr, "fopen: cannot close file\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

char* input(FILE* shakespeare, int* string_length) {
    *string_length = 0;  // изачальная длина любой строки - 0
    int capacity = 256;  // вместительность строки

    char* s = (char*) calloc(capacity, sizeof(char));

    if (s == NULL) {
        fprintf(stderr, "input: cannot allocate memory\n");
        return NULL;
    }

    int num = 0;
    // читаем по 128 либо пока не встретим '\n' или '\r'
    // в конце получиаем число считанных символов
    while ((fscanf(shakespeare, "%128[^\n\r]%n", s + *string_length, &num)) > 0) {
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

void qs(int *s_arr, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do         {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)             {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}

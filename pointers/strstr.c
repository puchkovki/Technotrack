// "Copyright 2020 Puchkov Kyryll"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* strstr_(const char * string1, const char * string2);
int strcmp_(char* string1, char* string2);

int main(void) {
    char str[] = "Эта программа написана в Linux Ubuntu 20.04.1 LTS";
    printf("%s\n", strstr_(str, "Linux"));

    if (strstr_(str, "Linux") == strstr(str, "Linux")) {
        printf("Ok!");
    } else {
        printf("Failed!");
    }

    return EXIT_SUCCESS;
}

char* strstr_(const char * string1, const char * string2) {
    size_t string1_size = strlen(string1);
    size_t string2_size = strlen(string2);
    size_t dist = string1_size - string2_size;

    for (int i = 0; i < dist; ++i) {
        if (strcmp_(string1 + i, string2)) {
            return string1 + i;
        }
    }

    return NULL;
}

int strcmp_(char* string1, char* string2) {
    size_t string1_size = strlen(string1);
    size_t string2_size = strlen(string2);

    /*if (string1_size < string2_size) {
        return 0;
    }*/

    for (int i = 0; i < string2_size; ++i) {
        if (string1[i] != string2[i]) {
            return 0;
        }
    }
    return 1;
}
Программы, реализующие функцию Input(), позволяющую вводить строку, и:
 - принимающей указатель на буфер, куда запишется вводимая строка: через [getchar](input/getchar_1.c) и через [scanf](input/scanf_1.c);
 - возвращающей указатель на статический буфер внутри функции: через [scanf](input/scanf_1.c);
 - возвращающей указатель на буфер со введенной строкой в динамической памяти: через [getchar](input/getchar_3.c) и через [scanf](input/scanf_3.c).

Эквиваленты стандартных функций:
 - [strlen](str/strlen.c)
 - [strncpy](str/strncpy.c)
 - [strncat](str/strncat.c)
 - [strstr](str/strstr.c)
 - [strtok](str/strtok.c)

[Попытка](shakespeare.c) сортировки [стихов Шекспира](shakespeare.txt).
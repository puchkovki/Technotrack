gcc -Wall -Wextra -pedantic -O0 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wcast-qual \
-Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=undefined \
-fno-sanitize-recover=all -fstack-protector -fsanitize=address,undefined -o test $1 \
& ./test > tests/"$1_test.txt"
#include <unistd.h>

int mx_atoi(const char *str);

static void printbinary(int num) {
    char str[] = "00000000000000000000000000000000\n";

    for (int i = 0; i < 32; ++i) {
        str[i] += !!(2147483648 & num);
        num <<= 1;
    }
    write(1, str, 33);
}

int main(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        printbinary(mx_atoi(av[i]));
    }
}

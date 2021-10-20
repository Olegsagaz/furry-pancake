#include <stdbool.h>

bool mx_isdigit(char c);
bool mx_isspace(char c);

int mx_atoi(const char *str) {
    int sign = 0;
    long res = 0;

    if (*str == '+' || *str == '-') {
        sign = *str++ == '-';
    }

    for (; mx_isdigit(*str); ++str) {
        if ((res = res * 10 + *str - 48) < 0) {
            return sign - 1;
        }
    }
    return *str ? 0 : (sign ? -res : res);
}

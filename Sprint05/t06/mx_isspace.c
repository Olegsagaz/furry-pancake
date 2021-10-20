#include <stdbool.h>

bool mx_isspace(char c) {
    return c == 32 || (c > 8 && c < 14);
}

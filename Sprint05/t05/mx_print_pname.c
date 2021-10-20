#include <stdlib.h>

void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strlen(const char *s);

static char *strrchr(const char *s, int c) {
    const char *str = s + mx_strlen(s);

    for (; str != s; --str) {
        if (*str == c) {
            return (char *)str;
        }
    }
    return NULL;
}

int main(int ac, char **av) {
    char *name = strrchr(*av, '/');

    if (name) {
        mx_printstr(name + 1);
        mx_printchar('\n');
    }
    (void)ac;
}

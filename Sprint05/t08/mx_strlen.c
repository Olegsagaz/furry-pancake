int mx_strlen(const char *s) {
    const char *str = s;

    while (*s) {
        ++s;
    }
    return s - str;
}

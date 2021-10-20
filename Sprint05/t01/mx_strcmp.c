int mx_strcmp(const char *s1, const char *s2) {
    if (s1 == s2 && s1) {
        return 0;
    }

    for (; *s1 == *s2 && *s1 && *s2; ++s1) {
        ++s2;
    }
    return *s1 - *s2;
}

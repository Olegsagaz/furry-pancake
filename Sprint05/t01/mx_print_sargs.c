void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

static void swap(char **s1, char **s2) {
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

static void sort(char **arr, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            if (mx_strcmp(arr[j - 1], arr[j]) > 0) {
                swap(arr + j - 1, arr + j);
            }
        }
    }
}

int main(int ac, char **av) {
    sort(av + 1, ac - 1);

    for (int i = 1; i < ac; ++i) {
        mx_printstr(av[i]);
        mx_printchar('\n');
    }
}

int mx_atoi(const char *str);

void mx_printint(int num);
void mx_printchar(char c);

int main(int ac, char **av) {
    long long result = 0;

    for (int i = 1; i < ac; ++i) {
        result += mx_atoi(av[i]);
    }

    mx_printint(result);
    mx_printchar('\n');
}

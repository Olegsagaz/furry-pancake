int mx_factorial_iter(int n) {
    int result = 1;

    if (n < 0 || n > 12) {
        return 0;
    }

    for (int i = n; i > 1; --i) {
        result *= i;
    }
    return result;
}

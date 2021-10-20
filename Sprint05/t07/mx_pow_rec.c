double mx_pow_rec(double n, unsigned int pow) {
    return pow == 0 ? 1 : mx_pow_rec(n, pow - 1) * n;
}

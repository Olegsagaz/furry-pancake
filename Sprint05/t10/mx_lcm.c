int mx_gcd(int a, int b);

int mx_lcm(int a, int b) {
    int mul = a * b;
    int gcd = mx_gcd(a, b);

    return (mul < 0 ? -mul : mul) / (gcd ? gcd : 1);
}

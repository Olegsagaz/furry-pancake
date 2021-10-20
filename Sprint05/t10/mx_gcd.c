int mx_gcd(int a, int b) {
    return b == 0 ? (a < 0 ? -a : a) : mx_gcd(b, a % b);
}

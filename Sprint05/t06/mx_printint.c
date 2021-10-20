#include <unistd.h>

inline static int numlen(int nbr) {
    int result = nbr <= 0;

    for (; nbr; nbr /= 10) {
        ++result;
    }
    return result;
}

void mx_printint(int nbr) {
    char str[12] = {'-'};
    long long int copy = nbr;
    int len = numlen(nbr);

    copy = copy < 0 ? -copy : copy;
    for (int i = len - 1; i >= (nbr < 0); --i) {
        str[i] = '0' + copy % 10;
        copy /= 10;
    }
    write(1, str, len);
}

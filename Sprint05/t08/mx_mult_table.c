#include <stdbool.h>

bool mx_isdigit(int c);
void mx_printint(int num);
void mx_printchar(char c);
int mx_atoi(const char *str);

static bool check_args(char **av) {
    bool check0 = mx_isdigit(av[0][0]) && av[0][1] == '\0';
    bool check1 = mx_isdigit(av[1][0]) && av[1][1] == '\0';

    return check0 && check1;
}

static void check_order(int *nums) {
    int temp = *nums;

    if (nums[0] > nums[1]) {
        nums[0] = nums[1];
        nums[1] = temp;
    }
}

static void print_table(int *nums) {
    for (int i = nums[0]; i <= nums[1]; ++i) {
        for (int j = nums[0]; j < nums[1]; ++j) {
            mx_printint(j * i);
            mx_printchar('\t');
        }

        mx_printint(nums[1] * i);
        mx_printchar('\n');
    }
}

int main(int ac, char **av) {
    if (ac == 3 && check_args(av + 1)) {
        int nums[2] = {mx_atoi(av[1]), mx_atoi(av[2])};

        check_order(nums);
        print_table(nums);
    }
}

#include <stdio.h>
#include <math.h>

int main() {
    int num, a, b, c, temp;
    for (num = 100; num < 999; num++) {
        temp = (int)pow(num, 1.0 / 3) + 1;
        for (a = 4; a < temp; a++) {
            for (b = 0; b <= a; b++) {
                for (c = 0; c <= b; c++) {
                    if (pow(a, 3) + pow(b, 3) + pow(c, 3) == num) {
                        printf("%d\n", num);
                    }
                }
            }
        }
    }
    getchar();
    return 0;
}

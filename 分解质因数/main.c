#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int num);

int temp;

int main() {
    int t, num;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &num);
        while (!is_prime(num)) {
            printf("%d ", temp);
            num /= temp;
        }
        printf("%d \n", num);
    }
    return 0;
}

bool is_prime(int num) {
    int s = (int)sqrt(num) + 1;
    for (temp = 2; temp < s; temp++) {
            if (num % temp == 0) {
                return false;
            }
    }
    return true;
}

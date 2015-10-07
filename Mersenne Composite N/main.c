#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(long long int num);
long long int temp;

int main() {
    int k, count;
    long long int num, n;
    scanf("%d", &k);
    for (count = 0; count <= k && count < 60; count++) {
        if (is_prime(count)) {
            n = num = pow(2, count) - 1;
            if (!is_prime(num)) {
                do {
                    printf("%lld * ", temp);
                    num /= temp;
                } while (!is_prime(num));
                printf("%lld = %lld = ( 2 ^ %d ) - 1\n",
                    num, n, count);
            }
        }
    }
    return 0;
}

bool is_prime(long long int num) {
    long long int s = (long long int)sqrt(num) + 1;
    for (temp = 2; temp < s; temp++) {
            if (num % temp == 0) {
                return false;
            }
    }
    return true;
}

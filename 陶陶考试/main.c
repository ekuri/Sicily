#include <stdio.h>

int main () {
    int n, max, count, temp;
    scanf("%d", &n);
    while (n) {
        for (count = 0, max = 0; count < n; count++) {
            scanf("%d", &temp);
            if (!count || max < temp)
                max = temp;
        }
        printf("%d\n", max);
        scanf("%d", &n);
    }
    return 0;
}

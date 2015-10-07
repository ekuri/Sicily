#include <stdio.h>

int main() {
    int m, n, x, y;
    scanf("%d %d", &m, &n);
    while (m && n) {
        y = (n - 2 * m) / 2;
        x = m - y;
        if (y < 0 || x < 0)
            printf("No answer\n");
        else
            printf("%d %d\n", x, y);
        scanf("%d %d", &m, &n);
    }
    return 0;
}

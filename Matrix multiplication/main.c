#include <stdio.h>

int main() {
    int n, m1[10][10], m2[10][10], m3, temp, count, x;
    while (scanf("%d", &n) != EOF) {
        for (count = 0; count < n; count++) {
            for (temp = 0; temp < n; temp++) {
                scanf("%d", &m1[count][temp]);
            }
        }
        for (count = 0; count < n; count++) {
            for (temp = 0; temp < n; temp++) {
                scanf("%d", &m2[count][temp]);
            }
        }
        for (count = 0; count < n; count++) {
            for (temp = 0; temp < n; temp++) {
                for (x = 0, m3 = 0; x < n; x++)
                    m3 += m1[count][x] * m2[x][temp];
                printf("%d", m3);
                if (temp == n - 1)
                    printf("\n");
                else
                    printf(" ");
            }
        }
    }
    return 0;
}

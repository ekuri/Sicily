#include <stdio.h>

int main() {
    int n, m, min, max, all, temp, score;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        for (temp = 0, min = 100, max = 0, all = 0; temp < m; temp++) {
            scanf("%d", &score);
            all += score;
            if (min > score)
                min = score;
            if (max < score)
                max = score;
        }
        all -= min + max;
        printf("%.2lf\n", all * 1.0 / (m - 2));
    }
    return 0;
}

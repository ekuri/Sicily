#include <stdio.h>

int main() {
    int n, m, count, temp, num;
    float score, s;
    scanf("%d %d", &n, &m);
    for (count = 0, num = 0; count < n; count++) {
        for (temp = 0, score = 0; temp < m; temp++) {
            scanf("%f", &s);
            score += s;
        }
        score /= 1.0 * m;
        printf("%.2f\n", score);
        if (score < 60)
            num++;
    }
    printf("%d\n", num);
    return 0;
}

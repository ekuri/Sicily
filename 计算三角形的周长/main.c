#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x1, x2, x3, y1, y2, y3, length;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
        length = 0;
        length += sqrt(fabs((y2 - y1) * ( y2 - y1) + (x2 - x1) * (x2 - x1)));
        length += sqrt(fabs((y3 - y1) * ( y3 - y1) + (x3 - x1) * (x3 - x1)));
        length += sqrt(fabs((y2 - y3) * ( y2 - y3) + (x2 - x3) * (x2 - x3)));
        printf("%.5lf\n", length);
    }
    return 0;
}

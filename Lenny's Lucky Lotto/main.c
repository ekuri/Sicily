#include <stdio.h>
#include <stdbool.h>

int result = 0, n, m, max[10], min[10]; 

bool next(int pos);

int main() {
    int num, count, temp;
    scanf("%d", &num);
    for (count = 0; count < num; count++) {
        result = 0;
        scanf("%d %d", &n, &m);
        temp = n - 1;
        max[temp] = m;
        while (temp--) {
            max[temp] = max[temp + 1] / 2;
        }
        for (temp = 1, min[0] = 1; temp < n; temp++) {
            min[temp] = min[temp - 1] * 2;
        }
        if (min[n - 1] <= max[n - 1]) {
            do {
                result += max[n - 1] - min[n - 1] + 1;
            } while (next(n - 2));
        }
        printf("Case %d: n = %d, m = %d, # lists = %d\n",
            count + 1, n, m, result);
    }
    getchar();
    getchar();
    return 0;
}

bool next(int pos) {
    int temp;
    if (pos < 0)
        return false;
    if (min[pos] < max[pos]) {
        min[pos]++;
        for (temp = pos + 1; temp < n ;temp++) {
            min[temp] = min[temp - 1] * 2;
        }
        return true;
    } else {
        return next(pos - 1);
    }
}

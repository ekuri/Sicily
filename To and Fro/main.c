#include <stdio.h>
#include <string.h>

int main() {
    char str[10000], result[10000];
    char temp[100][100];
    int col, row;
    int count, len, r, c, d;
    scanf("%d", &col);
    while (col) {
        scanf("%s", str);
        len = strlen(str);
        row = len / col;
        temp[0][0] = str[0];
        for (count = 1, r = 0, c = 1, d = 1; count < len; count++) {
            temp[r][c] = str[count];
            if (c + d == col || c + d == -1) {
                c += d;
                d = -d;
                r++;
            }
            c += d;
        }
        for (count = 0, r = 0, c = 0; count < len; count++) {
            result[count] = temp[r][c];
            r++;
            if (r == row) {
                r = 0;
                c++;
            }
        }
        result[len] = '\0';
        printf("%s\n", result);
        scanf("%d", &col);
    }
    return 0;
}

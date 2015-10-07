#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int num, testCount, count, temp, find, pos;
    char data[100][101], final[10000], minStr[101], first[201], second[201];
    bool flag[100];
    scanf("%d", &testCount);
    for (count = 0; count < testCount; count++) {
        strcpy(final, "");
        scanf("%d", &num);
        for (temp = 0; temp < num; temp++) {
            scanf("%s", data[temp]);
            flag[temp] = true;
        }
        for (temp = 0; temp < num; temp++) {
            if (!flag[temp])
                continue;
            strcpy(minStr, data[temp]);
            pos = temp;
            for (find = 0; find < num; find++) {
                if (!flag[find])
                    continue;
                strcpy(first, minStr);
                strcat(first, data[find]);
                strcpy(second, data[find]);
                strcat(second, minStr);
                if (strcmp(first, second) > 0) {
                    strcpy(minStr, data[find]);
                    pos = find;
                }
            }
            strcat(final, minStr);
            flag[pos] = false;
            temp = -1;
        }
        printf("%s\n", final);
    }
    return 0;
}

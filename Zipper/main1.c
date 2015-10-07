#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int num, count, data_len ,data1_len, data2_len;
char data1[10001], data2[10001], data[20001];

bool find_result(int pos, int pos1, int pos2);

int main() {
    int temp;
    scanf("%d", &num);
    for (count = 1; count <= num; count++) {
        scanf("%s %s %s", data1, data2, data);
        data_len = strlen(data);
        data1_len = strlen(data1);
        data2_len = strlen(data2);
        if (data_len != data1_len + data2_len) {
            printf("Data set %d: no\n", count);
            continue;
        }
        if (find_result(data_len - 1, data1_len - 1, data2_len - 1))
            printf("Data set %d: yes\n", count);
        else
            printf("Data set %d: no\n", count);
    }
    return 0;
}

bool find_result(int pos, int pos1, int pos2) {
    bool result = false;
    if (pos < 0)
        return true;
    if (pos1 >= 0 && data[pos] == data1[pos1])
        result = result || find_result(pos - 1, pos1 - 1, pos2);
    if (pos2 >= 0 && data[pos] == data2[pos2])
        result = result ||  find_result(pos - 1, pos1, pos2 - 1);
    return result;
}

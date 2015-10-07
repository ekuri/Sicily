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
        if (find_result(0, 0, 0))
            printf("Data set %d: yes\n", count);
        else
            printf("Data set %d: no\n", count);
    }
    return 0;
}

bool find_result(int pos, int pos1, int pos2) {
    int next = 0;
    if (pos >= data_len)
        return true;
    if (data[pos] == data1[pos1] && data[pos] == data2[pos2]) {
        while (true) {
            next++;
            if (pos1 + next >= data1_len)
                return find_result(pos + next, pos1, pos2 + next);
            else if (pos2 + next >= data2_len)
                return find_result(pos + next, pos1 + next, pos2);
            if (data[pos + next] == data1[pos1 + next] &&
                    data[pos + next] == data2[pos2 + next])
                continue;
            if (data[pos + next] == data1[pos1 + next])
                return find_result(pos + next + 1, pos1 + next + 1, pos2);
            else if (data[pos + next] == data2[pos2 + next])
                return find_result(pos + next + 1, pos1, pos2 + next + 1);
            return find_result(pos + next, pos1 + next, pos2);
        }
    } else if (data[pos] == data1[pos1])
        return find_result(pos + 1, pos1 + 1, pos2);
    else if (data[pos] == data2[pos2])
        return find_result(pos + 1, pos1, pos2 + 1);
    return false;
}

/* 
 * File:   main.c
 * Author: ekuri
 *
 * Created on 2014年9月3日, 上午11:44
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * 
 */

/*char map[750][751];
int x, y, result, temp_result, find;
bool map_find[750][750];

int find_next();
void find_result(int pos_x, int pos_y);

int main(int argc, char** argv) {
    int count, temp;
    scanf("%d %d", &y, &x);
    for (count = 0; count < x; count++) {
        scanf("%s", map[count]);
    }
    for (count = 0; count < x; count++) {
        for (temp = 0; temp < y; temp++) {
            if (map[count][temp] == '.')
                map_find[count][temp] = true;
            else
                map_find[count][temp] = false;
        }
    }
    printf("%d\n", find_next());
    return (EXIT_SUCCESS);
}

int find_next() {
    int count, temp;
    for (count = 0, result = 0; count < x; count++) {
        for (temp = 0; temp < y; temp++) {
            find = 0;
            if (map_find[count][temp]) {
                find_result(count, temp);
                temp_result = find;
            }
            if (result < temp_result)
                result = temp_result;
        }
    }
    return result;
}

void find_result(int pos_x, int pos_y) {
    find++;
    int count, temp;
    map_find[pos_x][pos_y] = false;
    for (count = -1; count < 2; count++) {
        for (temp = -1; temp < 2; temp++) {
            if (pos_x + count < 0 || pos_x + count >= x || pos_y + temp < 0 ||
                    pos_y + temp >= y)
                continue;
            if (map_find[pos_x + count][pos_y + temp])
                find_result(pos_x + count, pos_y + temp);
        }
    }
}
*/

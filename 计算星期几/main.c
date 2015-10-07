/* 
 * File:   main.c
 * Author: ekuri
 *
 * Created on 2014年9月2日, 下午11:11
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char day[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday"};
    int t, m, d, temp, count;
    int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &m, &d);
        count = 0;
        for (temp = 1; temp < m; temp++) {
            count += date[temp - 1];
        }
        count += d - 1;
        count %= 7;
        count += 6;
        count %= 7;
        //printf("%d\n", count);
        printf("%s\n", day[count]);
    }
    return (EXIT_SUCCESS);
}


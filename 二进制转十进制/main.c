/* 
 * File:   main.c
 * Author: ekuri
 *
 * Created on 2014年9月3日, 上午12:01
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int t, str_len, count, result, temp, mid;
    char num[32];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", num);
        result = 0;
        str_len = strlen(num);
        for (count = str_len - 1; count >= 0; count--) {
            if (num[count] == '1') {
                mid = 1;
                for (temp = 0; temp < str_len - count - 1; temp++) {
                    mid *= 2;
                }
                result += mid;
            }
        }
        printf("%d\n", result);
    }
    return (EXIT_SUCCESS);
}


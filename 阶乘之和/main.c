/* 
 * File:   main.c
 * Author: ekuri
 *
 * Created on 2014年9月2日, 下午11:40
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int n, temp, count, result = 0, mid;
    scanf("%d", &n);
    for (count = 1, result = 0, mid = 1; count <= n; count++) {
        mid *= count;
        if (mid > 1000000)
            mid %= 1000000;
        result += mid;
        if (result >= 1000000)
            result %= 1000000;
    }
    printf("%d\n", result);
    return (EXIT_SUCCESS);
}


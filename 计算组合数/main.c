/* 
 * File:   main.c
 * Author: ekuri
 *
 * Created on 2014年9月2日, 下午10:20
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int n, m, result, count, temp;
    scanf("%d %d", &n, &m);
    while (n || m) {
        result = 1;
        for (count = n; count > n - m; count--) {
            result *= count;
        }
        for (count = 2; count <= m; count++) {
            result /= count;
        }
        printf("%d\n", result);
        scanf("%d %d", &n, &m);
    }
    return (EXIT_SUCCESS);
}


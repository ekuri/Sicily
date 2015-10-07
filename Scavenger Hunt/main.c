/* 
 * File:   main.c
 * Author: ekuri
 *
 * Created on 2014年9月3日, 上午11:10
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int p, q, x[1000], y[1000], x_len, y_len, count, temp;
    scanf("%d %d", &p, &q);
    for (count = 1, x_len = 0; count <= p; count++) {
        if (p % count == 0) {
            x[x_len] = count;
            x_len++;
        }
    }
    for (count = 1, y_len = 0; count <= q; count++) {
        if (q % count == 0) {
            y[y_len] = count;
            y_len++;
        }
    }
    for (count = 0; count < x_len; count++) {
        for (temp = 0; temp < y_len; temp++) {
            printf("%d %d\n", x[count], y[temp]);
        }
    }
    return (EXIT_SUCCESS);
}


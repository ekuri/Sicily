/* 
 * File:   main.c
 * Author: ekuri
 *
 * Created on 2014年9月3日, 上午10:41
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int t, a = 0, b = 0, c = 0, count;
    double j, p, pa = 0, pb = 0, pc = 0, p1 = 0, p2 = 0, p3 = 0;
    scanf("%d", &t);
    for (count = 1; count <= t; count++) {
        scanf("%lf %lf", &j, &p);
        if (pa < j / p) {
            c = b;
            b = a;
            a = count;
            pc = pb;
            pb = pa;
            pa = j / p;
            p3 = p2;
            p2 = p1;
            p1 = p;
        } else if (pb < j / p) {
            c = b;
            b = count;
            pc = pb;
            pb = j /p;
            p3 = p2;
            p2 = p;
        } else if (pc < j / p) {
            c = count;
            pc = j / p;
            p3 = p;
        }
    }
    printf("%d\n", (int)(p1 + p2 + p3));
    printf("%d\n%d\n%d\n", a, b, c);
    return (EXIT_SUCCESS);
}


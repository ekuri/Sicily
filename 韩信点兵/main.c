/* 
 * File:   main.c
 * Author: ekuri
 *
 * Created on 2014年9月3日, 上午10:23
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int t, a, b, c, count, result;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        result = 0;
        for (count = 0; count < 15; count++) { 
            if ((count * 7 + c) % 3 == a && (count * 7 + c) % 5 == b &&
                    count * 7 + c >= 10 && count * 7 + c <= 100) {
                printf("%d\n", count * 7 + c);
                break;
            }
        }
        if (count == 15)
            printf("No answer\n");
    }
    return (EXIT_SUCCESS);
}

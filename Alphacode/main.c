/*
    main.c
    written by ekuri
    all right reserved
*/

#include <stdio.h>
#include <string.h>

char code[1000];
long sol, str_len;
void find_sol(int pos);

int main() {
    int pos; //position of process
    scanf("%s", code);
    // quit while input 0
    while (strcmp(code, "0")) {
        pos = 0;
        sol = 0;
        str_len = strlen(code);
        find_sol(pos);
        printf("%ld\n", sol);
        scanf("%s", code);
    }
    return 0;
}

void find_sol(int pos) {
    // it will get a valid decode method if make it to the end of string
    if (pos >= str_len) {
        sol++;
        return;
    }
    // 0 represent nothing
    if (code[pos] != '0') {
        if (((pos < str_len - 1) && (pos[code + 1] != '0')) ||
                (pos == str_len - 1)) {
            find_sol(pos + 1);
        }
    }
    // if the number is between 10 and 26, it will be another decode method
    if ((pos < str_len - 1) && ((code[pos] == '1') ||
            (code[pos] == '2' && code[pos + 1] < '7'))) {
        find_sol(pos + 2);
    }
}

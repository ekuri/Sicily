#include <stdio.h>
#include <string.h>

char code[100000];
int sol;

int find_sol(int pos_l, int pos_r);
int find_decode1(int pos_l, int pos_r);
int find_decode2(int pos_l, int pos_r);

int main() {
    int pos_l, pos_r;
    scanf("%s", code);
    while (strcmp(code, "0")) {
        pos_l = 0;
        pos_r = strlen(code) - 1;
        sol = 0;
        sol = find_sol(pos_l, pos_r);
        printf("%d\n", sol);
        scanf("%s", code);
    }
    return 0;
}
int find_sol(int pos_l, int pos_r) {
    int extra = 0;
    if (pos_r - pos_l == 0 || pos_r - pos_l == 1)
        return find_decode1(pos_l, pos_r);
    if (find_decode2((pos_l + pos_r) / 2, (pos_l + pos_r) / 2 + 1)) {
        extra = 1;
        if (pos_r - pos_l == 2)
            extra = find_sol(pos_l, pos_l);
        if ((pos_r - pos_l >= 3))
            extra = find_sol(pos_l, (pos_l + pos_r) / 2 - 1) *
                find_sol((pos_l + pos_r) / 2 + 2, pos_r);
    }
    return find_sol(pos_l, (pos_l + pos_r) / 2) *
            find_sol((pos_l + pos_r) / 2 + 1, pos_r) + extra;
}
int find_decode1(int pos_l, int pos_r) {
    if (pos_r == pos_l) {
        if (code[pos_l] >= '1' && code[pos_l] <= '9')
            return 1;
        else
            return 0;
    } else if (pos_r - pos_l == 1) {
        return find_decode1(pos_l, pos_l) *
                find_decode1(pos_r, pos_r) + find_decode2(pos_l, pos_r);
    }
}
int find_decode2(int pos_l, int pos_r) {
    if (code[pos_l] == '1' || (code[pos_l] == '2' && code[pos_r] <= '6'))
        return 1;
    return 0;
}

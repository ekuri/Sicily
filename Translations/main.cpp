#include <stdio.h>
#include <string.h>


int main() {
    char f_lang[250][2][20], s_lang[250][2][20];
    char result[25][2][20], f[25][20], s[25][20];
    int f_[25][2], s_[25][2];
    int num;
    int count, word, temp;
    scanf("%d", &num);
    while (num) {
        for (count = 0; count < num; count++) {
            scanf("%s %s", f_lang[count][0], f_lang[count][1]);
        }
        for (count = 0; count < num; count++) {
            scanf("%s %s", s_lang[count][0], s_lang[count][1]);
        }
        strcpy(f[0], f_lang[0][0]);
        word = 1;
        for (count = 1; count < num; count++) {
            for (temp = 0; temp < word; temp++) {
                if (!strcmp(f[temp], f_lang[count][0]))
                    break;
                if (temp == word - 1) {
                    strcpy(f[word], f_lang[count][0]):
                    word++;
                }
            }
            for (temp = 0; temp < word; temp++) {
                if (!strcmp(f[temp], f_lang[count][1]))
                    break;
                if (temp == word - 1) {
                    strcpy(f[word], f_lang[count][1]):
                    word++;
                }
            }
        }
        
        scanf("%d", &num);
    }
    return 0;
}


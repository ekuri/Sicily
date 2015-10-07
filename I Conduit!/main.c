#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  int count, temp, find;
  struct _cood {
        double x1, x2, y1, y2;
        double k;
        bool k_able;
  } cood[1000], c_temp;
  scanf("%d", &count);
  while (count != 0) {
        for (temp = 0; temp < count; temp++) {
            scanf("%lf %lf %lf %lf", &cood[temp].x1,
                &cood[temp].y2, &cood[temp].x2, &cood[temp].y2);
            if (cood[temp].x1 == cood[temp].x2) {
                cood[temp].k_able = false;
            } else {
                cood[temp].k_able = true;
                cood[temp].k = (cood[temp].y2 - cood[temp].y1) /
                    (cood[temp].x2 - cood[temp].x1);
            }
            if (cood[temp].y1 > cood[temp].y2) {
                c_temp.x1 = cood[temp].x2;
                c_temp.y1 = cood[temp].y2;
                cood[temp].x2 = cood[temp].x1;
                cood[temp].y2 = cood[temp].y1;
                cood[temp].x1 = c_temp.x1;
                cood[temp].y1 = c_temp.y1;
            }
        }
        for (temp = 0; temp < count; temp++) {
            for (find = 0; find < temp; find++) {
                if (!cood[temp].k_able) {
                    if (!cood[find].k_able) {
                        if (!(cood[temp].y1 > cood[find].y2 ||
                            cood[temp].y2 < cood[find].y1)) {
                            count--;
                            break;
                        }
                    }
                } else {
                    if (cood[temp].k == cood[find].k) {
                        if (!(cood[temp].y1 > cood[find].y2 ||
                            cood[temp].y2 < cood[find].y1)) {
                            count--;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", count);
        scanf("%d", &count);
  }
  printf("Press enter to continue ...");
  getchar();
  return 0;
}

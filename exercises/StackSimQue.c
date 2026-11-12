#include <stdio.h>

int main(void)
{
    int n1, n2;
    int in[100], out[100];
    int topIn = 0, topOut = 0;
    int minCap, maxCap, item;
    char op;

    scanf("%d%d", &n1, &n2);

    minCap = n1 < n2 ? n1 : n2;
    maxCap = n1 > n2 ? n1 : n2;

    while (scanf(" %c", &op) == 1 && op != 'T') {
        if (op == 'A') {
            scanf("%d", &item);

            if (topIn < minCap) {
                in[topIn++] = item;
            } else if (topOut == 0) {
                while (topIn > 0) {
                    out[topOut++] = in[--topIn];
                }
                in[topIn++] = item;
            } else {
                printf("ERROR:Full\n");
            }
        } else if (op == 'D') {
            if (topOut == 0) {
                if (topIn == 0) {
                    printf("ERROR:Empty\n");
                    continue;
                }

                while (topIn > 0) {
                    out[topOut++] = in[--topIn];
                }
            }

            printf("%d\n", out[--topOut]);
        }
    }

    return 0;
}

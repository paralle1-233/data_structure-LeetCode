#include <stdio.h>

int main(void)
{
    int n, a[10000], b[10000];
    int x, i, na = 0, nb = 0;
    int ia = 0, ib = 0, count = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 1)
            a[na++] = x;
        else
            b[nb++] = x;
    }

    while (ia < na || ib < nb) {
        for (i = 0; i < 2 && ia < na; i++) {
            if (count++)
                printf(" ");
            printf("%d", a[ia++]);
        }

        if (ib < nb) {
            if (count++)
                printf(" ");
            printf("%d", b[ib++]);
        }
    }

    printf("\n");

    return 0;
}

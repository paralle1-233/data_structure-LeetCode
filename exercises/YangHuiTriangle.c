#include <stdio.h>

int main(void) {
    int n, a[10] = {0}, b[10] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        b[0] = 1;
        b[i] = 1;

        for (int j = 1; j < i; j++)
            b[j] = a[j - 1] + a[j];

        for (int j = 0; j <= i; j++) {
            printf("%4d", b[j]);
        }
        printf("\n");

        for (int j = 0; j <= i; j++)
            a[j] = b[j];
    }

    return 0;
}

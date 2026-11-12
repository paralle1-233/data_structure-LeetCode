#include <stdio.h>

double sum(int a[], int n) {
    if (n == 0)
        return 0;
    return a[n - 1] + sum(a, n - 1);
}

int main(void) {
    int n, a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("The average value is %.1f\n", sum(a, n) / n);
    return 0;
}

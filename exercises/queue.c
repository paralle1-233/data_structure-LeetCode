#include <stdio.h>

int main(void)
{
    int n, a[100], i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        a[i] = i + 1;

    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");

    return 0;
}

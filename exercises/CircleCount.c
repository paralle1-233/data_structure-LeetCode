#include <stdio.h>

int main(void)
{
    int n, i, remain = 0;
    scanf("%d", &n);

    for (i = 2; i <= n; i++)
        remain = (remain + 3) % i;

    printf("%d\n", remain + 1);

    return 0;
}

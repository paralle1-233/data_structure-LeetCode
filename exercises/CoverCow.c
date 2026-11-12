#include <stdio.h>

int main(void)
{
    int n, h[80000], stack[80000], top = -1;
    long long sum = 0;
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &h[i]);

    for (i = 0; i < n; i++) {
        while (top >= 0 && stack[top] <= h[i])
            top--;

        sum += top + 1;
        stack[++top] = h[i];
    }

    printf("%lld\n", sum);

    return 0;
}

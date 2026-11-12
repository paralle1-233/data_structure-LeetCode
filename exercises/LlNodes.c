#include <stdio.h>

int count(int n) {
    if (n == 0)
        return 0;
    return 1 + count(n - 1);
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x);
    printf("%d\n", count(n));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int max(int *a, int n) {
    if (n == 1)
        return a[0];
    int m = max(a, n - 1);
    return a[n - 1] > m ? a[n - 1] : m;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", max(a, n));
    free(a);
    return 0;
}

#include <stdio.h>

int main(void) {
    int n, m, k;
    int a[1000];

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int front = k - 1;
    int count = n;

    while (count > 0) {
        front = (front + m - 1) % count;
        printf("%d", a[front]);

        for (int i = front; i < count - 1; i++)
            a[i] = a[i + 1];

        count--;

        if (count > 0) {
            printf(" ");
            front %= count;
        }
    }

    printf("\n");
    return 0;
}

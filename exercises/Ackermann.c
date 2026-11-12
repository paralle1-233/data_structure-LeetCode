#include <stdio.h>

int Ack(int m, int n) {
    if (m == 0)
        return n + 1;
    if (n == 0)
        return Ack(m - 1, 1);
    return Ack(m - 1, Ack(m, n - 1));
}

int main(void) {
    int m, n;
    scanf("%d%d", &m, &n);
    printf("Ack(%d,%d)=%d\n", m, n, Ack(m, n));
    return 0;
}

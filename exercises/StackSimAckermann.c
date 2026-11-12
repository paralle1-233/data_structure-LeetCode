#include <stdio.h>
#include <stdlib.h>

/* 利用特性：递归可以转化为栈
 * 开辟足够大空间防止栈溢出（Stack Overflow）
 * */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n, a, b, top = 0;
    int *stack = malloc(100000 * sizeof(int));
    scanf("%d%d", &a, &b);
    m = a;
    n = b;
    stack[top++] = m;

    while (top > 0) {
        m = stack[--top];
        if (m == 0)
            n++;
        else if (n == 0) {
            n = 1;
            stack[top++] = m - 1;
        } else {
            stack[top++] = m - 1;
            stack[top++] = m;
            n--;
        }
    }

    printf("Ack(%d,%d)=%d\n", a, b, n);
    free(stack);
    return 0;
}

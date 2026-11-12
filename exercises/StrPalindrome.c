#include <stdio.h>

int main(void) {
    char stack[1000], queue[1000], ch;
    int top = -1, front = 0, rear = 0;

    while (scanf("%c", &ch) == 1 && ch != '@') {
        stack[++top] = ch;
        queue[rear++] = ch;
    }

    while (top >= 0) {
        if (stack[top--] != queue[front++]) {
            printf("此字符串不是回文\n");
            return 0;
        }
    }

    printf("此字符串为回文\n");
    return 0;
}

#include <stdio.h>

int main(void) {
    int a[17], front = 0, rear = 9;

    for (int i = 0; i < 9; i++)
        scanf("%d", &a[i]);

    while (front < rear) {
        printf("%d", a[front++]);
        if (front < rear)
            printf(" ");
        if (front < rear)
            a[rear++] = a[front++];
    }

    printf("\n");
    return 0;
}

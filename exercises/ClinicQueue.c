#include <stdio.h>

int main(void) {
    int queue[1000], front = 0, rear = 0, id = 0;
    char op;
    int closed = 0;

    while (scanf(" %c", &op) == 1) {
        if (closed) {
            printf("ERROR\n");
            continue;
        }

        if (op == 'a') {
            queue[rear++] = ++id;
            printf("Your patient's No. is:%d.\n", id);
            printf("There are %d patient(s) waiting ahead of you.\n",
                   rear - front);
        } else if (op == 'n') {
            if (front < rear) {
                printf("Patient No. %d, please go to the clinic\n",
                       queue[front++]);
            } else {
                printf("ERROR\n");
            }
        } else if (op == 'q') {
            printf("It is the end of today. Following patients please go to the clinic in turn:");
            while (front < rear) {
                printf("%d", queue[front++]);
                if (front < rear)
                    printf(",");
            }
            printf("\n");
            closed = 1;
        } else {
            printf("ERROR\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *reverse(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        Node *p = malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p;
    }
    head = reverse(head);
    for (Node *p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    return 0;
}

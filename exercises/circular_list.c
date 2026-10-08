#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createList(void)
{
    Node *head, *p, *tail;
    int i;

    head = (Node *)malloc(sizeof(Node));
    head->data = '\0';
    head->prev = NULL;
    head->next = NULL;

    tail = NULL;

    for (i = 0; i < 26; i++) {
        p = (Node *)malloc(sizeof(Node));
        p->data = 'A' + i;

        if (head->next == NULL) {
            head->next = p;
            p->prev = head;
        } else {
            tail->next = p;
            p->prev = tail;
        }

        tail = p;
    }

    tail->next = head->next;
    head->next->prev = tail;

    return head;
}

void printList(Node *head, int n)
{
    Node *p;
    int i;

    p = head->next;

    if (n > 0) {
        for (i = 1; i < n; i++)
            p = p->next;
    } else {
        for (i = 0; i < -n; i++)
            p = p->prev;
    }

    for (i = 0; i < 26; i++) {
        printf("%c", p->data);
        p = p->next;
    }

    printf("\n");
}

void freeList(Node *head)
{
    Node *p, *next;
    int i;

    p = head->next;

    for (i = 0; i < 26; i++) {
        next = p->next;
        free(p);
        p = next;
    }

    free(head);
}

int main(void)
{
    Node *head;
    int n;

    scanf("%d", &n);

    head = createList();
    printList(head, n);
    freeList(head);

    return 0;
}

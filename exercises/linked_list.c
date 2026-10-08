#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *initList(void)
{
    Node *head = NULL, *tail = NULL, *p;
    int x;

    while (scanf("%d", &x) == 1 && x != -1) {
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;

        if (head == NULL)
            head = p;
        else
            tail->next = p;

        tail = p;
    }

    return head;
}

void printList(Node *head)
{
    Node *p = head;

    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL)
            printf(" ");
        p = p->next;
    }
    printf("\n");
}

Node *insertNode(Node *head, int i, int x)
{
    Node *p, *q;
    int j;

    p = (Node *)malloc(sizeof(Node));
    p->data = x;

    if (i == 1) {
        p->next = head;
        return p;
    }

    q = head;
    for (j = 1; j < i - 1 && q != NULL; j++)
        q = q->next;

    if (q == NULL) {
        free(p);
        return head;
    }

    p->next = q->next;
    q->next = p;

    return head;
}

Node *deleteNode(Node *head, int i)
{
    Node *p, *q;
    int j;

    if (head == NULL)
        return head;

    if (i == 1) {
        p = head;
        head = head->next;
        free(p);
        return head;
    }

    q = head;
    for (j = 1; j < i - 1 && q->next != NULL; j++)
        q = q->next;

    if (q->next == NULL)
        return head;

    p = q->next;
    q->next = p->next;
    free(p);

    return head;
}

int searchNode(Node *head, int i)
{
    Node *p = head;
    int j;

    for (j = 1; j < i && p != NULL; j++)
        p = p->next;

    return p->data;
}

void freeList(Node *head)
{
    Node *p;

    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
}

int main(void)
{
    Node *head;
    int i, x;

    head = initList();
    printList(head);

    scanf("%d,%d", &i, &x);
    head = insertNode(head, i, x);
    printList(head);

    scanf("%d", &i);
    head = deleteNode(head, i);
    printList(head);

    scanf("%d", &i);
    printf("%d\n", searchNode(head, i));

    freeList(head);

    return 0;
}


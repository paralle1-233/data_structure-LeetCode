#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createList(void)
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

Node *mergeList(Node *a, Node *b)
{
    Node head;
    Node *tail = &head;

    head.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a != NULL)
        tail->next = a;
    else
        tail->next = b;

    return head.next;
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
    Node *list1, *list2, *result;

    list1 = createList();
    list2 = createList();

    result = mergeList(list1, list2);

    printList(result);
    freeList(result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double coef;
    int exp;
    struct Node *next;
} Node;

Node *createList(void)
{
    Node *head = NULL, *tail = NULL, *p;
    double coef;
    int exp;

    while (scanf("%lf^%d", &coef, &exp) == 2) {
        if (coef == 0 && exp == 0)
            break;

        p = (Node *)malloc(sizeof(Node));
        p->coef = coef;
        p->exp = exp;
        p->next = NULL;

        if (head == NULL)
            head = p;
        else
            tail->next = p;

        tail = p;
    }

    return head;
}

Node *addList(Node *a, Node *b)
{
    Node *head = NULL, *tail = NULL, *p;
    double coef;

    while (a != NULL || b != NULL) {
        p = (Node *)malloc(sizeof(Node));
        p->next = NULL;

        if (a == NULL) {
            p->coef = b->coef;
            p->exp = b->exp;
            b = b->next;
        } else if (b == NULL) {
            p->coef = a->coef;
            p->exp = a->exp;
            a = a->next;
        } else if (a->exp > b->exp) {
            p->coef = a->coef;
            p->exp = a->exp;
            a = a->next;
        } else if (a->exp < b->exp) {
            p->coef = b->coef;
            p->exp = b->exp;
            b = b->next;
        } else {
            coef = a->coef + b->coef;

            if (coef == 0) {
                free(p);
                a = a->next;
                b = b->next;
                continue;
            }

            p->coef = coef;
            p->exp = a->exp;
            a = a->next;
            b = b->next;
        }

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
        if (p->coef == (long long)p->coef)
            printf("%lld^%d", (long long)p->coef, p->exp);
        else
            printf("%g^%d", p->coef, p->exp);

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
    Node *a, *b, *result;

    a = createList();
    b = createList();

    result = addList(a, b);

    printList(result);

    freeList(a);
    freeList(b);
    freeList(result);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

/* 先序建立二叉树 */
BiTree CreateBiTree(void) {
    int x;
    scanf("%d", &x);

    if (x == 0 || x == -1)
        return NULL;

    BiTree T = malloc(sizeof(BiTNode));
    T->data = x;
    T->lchild = CreateBiTree();
    T->rchild = CreateBiTree();

    return T;
}

/* 求每层最大值 */
void LevelMax(BiTree T) {
    if (T == NULL)
        return;

    BiTree queue[MAX];
    int front = 0, rear = 0;
    int first = 1;

    queue[rear++] = T;

    while (front < rear) {
        int size = rear - front;
        int max = INT_MIN;

        /* 处理当前层的所有节点 */
        for (int i = 0; i < size; i++) {
            BiTree cur = queue[front++];

            if (cur->data > max)
                max = cur->data;

            if (cur->lchild != NULL)
                queue[rear++] = cur->lchild;

            if (cur->rchild != NULL)
                queue[rear++] = cur->rchild;
        }

        /* 输出当前层最大值 */
        if (!first)
            printf(" ");

        printf("%d", max);
        first = 0;
    }
}

int main(void) {
    BiTree T = CreateBiTree();

    LevelMax(T);

    printf("\n");
    return 0;
}


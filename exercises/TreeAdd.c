
#include <stdio.h>
#include <stdlib.h>

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

/* 叠加二叉树 */
BiTree MergeBiTree(BiTree A, BiTree B) {
    if (A == NULL)
        return B;

    if (B == NULL)
        return A;

    BiTree T = malloc(sizeof(BiTNode));
    T->data = A->data + B->data;
    T->lchild = MergeBiTree(A->lchild, B->lchild);
    T->rchild = MergeBiTree(A->rchild, B->rchild);

    return T;
}

/* 输出广义表 */
void ListBiTree(BiTree T) {
    if (T != NULL) {
        printf("%d", T->data);

        if (T->lchild != NULL || T->rchild != NULL) {
            printf("(");
            ListBiTree(T->lchild);

            if (T->rchild != NULL)
                printf(",");

            ListBiTree(T->rchild);
            printf(")");
        }
    }
}

int main(void) {
    BiTree A, B, C;
    int end;

    A = CreateBiTree();

    scanf("%d", &end);  // 消费第一棵树的 -1

    B = CreateBiTree();

    C = MergeBiTree(A, B);

    ListBiTree(C);
    printf("\n");

    return 0;
}



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

/* 判断两棵树是否互为镜像 */
int IsMirror(BiTree A, BiTree B) {
    /* 两个节点都为空 */
    if (A == NULL && B == NULL)
        return 1;

    /* 只有一个节点为空 */
    if (A == NULL || B == NULL)
        return 0;

    /* 节点值不同 */
    if (A->data != B->data)
        return 0;

    /* 交叉比较左右子树 */
    return IsMirror(A->lchild, B->rchild)
        && IsMirror(A->rchild, B->lchild);
}

/* 判断整棵树是否对称 */
int IsSymmetric(BiTree T) {
    if (T == NULL)
        return 1;

    return IsMirror(T->lchild, T->rchild);
}

int main(void) {
    BiTree T = CreateBiTree();

    if (IsSymmetric(T))
        printf("二叉树是镜像对称的\n");
    else
        printf("二叉树不是镜像对称的\n");

    return 0;
}


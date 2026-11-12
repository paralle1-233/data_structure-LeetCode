
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

/* 判断以A、B为根的结构是否匹配 */
int MatchTree(BiTree A, BiTree B) {
    /* 树2已经匹配完 */
    if (B == NULL)
        return 1;

    /* 树1为空，但树2还有节点 */
    if (A == NULL)
        return 0;

    /* 当前节点值不相等 */
    if (A->data != B->data)
        return 0;

    /* 继续匹配左右子树 */
    return MatchTree(A->lchild, B->lchild)
        && MatchTree(A->rchild, B->rchild);
}

/* 判断树2是否为树1的子结构 */
int HasSubTree(BiTree A, BiTree B) {
    if (A == NULL || B == NULL)
        return 0;

    /* 当前节点可能是匹配起点 */
    if (MatchTree(A, B))
        return 1;

    /* 在树1的左、右子树继续寻找 */
    return HasSubTree(A->lchild, B)
        || HasSubTree(A->rchild, B);
}

int main(void) {
    BiTree T1, T2;
    int end;

    T1 = CreateBiTree();

    scanf("%d", &end);  // 消费第一棵树的 -1

    T2 = CreateBiTree();

    if (HasSubTree(T1, T2))
        printf("树2是树1的子结构\n");
    else
        printf("树2不是树1的子结构\n");

    return 0;
}


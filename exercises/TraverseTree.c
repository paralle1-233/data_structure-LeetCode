
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

/* 先序递归建树 */
Node *createTree(char *str, int *index) {
    if (str[*index] == '\0') {
        return NULL;
    }

    char ch = str[(*index)++];

    if (ch == '0') {
        return NULL;
    }

    Node *root = (Node *)malloc(sizeof(Node));
    root->data = ch;
    root->left = createTree(str, index);
    root->right = createTree(str, index);

    return root;
}

/* 层序遍历 */
void levelOrder(Node *root) {
    if (root == NULL) {
        return;
    }

    Node *queue[MAX];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node *cur = queue[front++];

        printf("%c", cur->data);

        if (cur->left != NULL) {
            queue[rear++] = cur->left;
        }

        if (cur->right != NULL) {
            queue[rear++] = cur->right;
        }
    }
}

int main(void) {
    char str[MAX];
    int index = 0;

    scanf("%999s", str);

    Node *root = createTree(str, &index);

    levelOrder(root);

    printf("\n");

    return 0;
}


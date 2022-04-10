#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    struct tree* right;
    struct tree* left;
    struct tree* parent;
    int data;
} tree;

// Инициализация дерева
void init(tree** n) {
    *n = (tree*)malloc(sizeof(tree));
    (*n)->right = NULL;
    (*n)->left = NULL;
    (*n)->data = 2147483647;
}

// Вставка значения в дерево:
// 0 - вставка выполнена успешно
// 1 - элемент существует
// 2 - не удалось выделить память для нового элемента
int insert(tree* n, int value) {
    if (n->data == 2147483647) {
        n->data = value;
        return 0;
    }
    if (n->data == value)
        return 1;
    if (value > n->data) {
        if (n->right)
            return(insert(n->right, value));
        else {
            n->right = (tree*)malloc(sizeof(tree));
            n->right->right = NULL;
            n->right->left = NULL;
            n->right->data = value;
            return 0;
        }
    }
    else {
        if (n->left)
            return(insert(n->left, value));
        else {
            n->left = (tree*)malloc(sizeof(tree));
            n->left->right = NULL;
            n->left->left = NULL;
            n->left->data = value;
            return 0;
        }
    }
    return 2;
}

void postorderTraversal(tree* t) {
    if (t == NULL) {
        return;
    }
    postorderTraversal(t->left);
    postorderTraversal(t->right);
    printf("%d ", (int)t->data);
}

int main() {
    tree* t;
    int i, a;
    init(&t);
    for (i = 0; i < 7; i++) {
        scanf("%d", &a);
        insert(t, a);
    }
    postorderTraversal(t);
    return 0;
}


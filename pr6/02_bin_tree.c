#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree
{
    struct tree* right;
    struct tree* left;
    struct tree* parent;
    int data;
} tree;

typedef struct stack_node
{
    struct tree* data;
    struct stack_node* next;
} stack_node;

typedef struct stack
{
    stack_node* head;
} stack;

//stack functions
void init_stack(stack* s) {
    s->head = NULL;
}

int push(stack* s, tree* n) {
    stack_node* snode = (stack_node*)malloc(sizeof(stack_node));
    snode->data = n;
    snode->next = s->head;
    s->head = snode;
    return 0;
}

tree* pop(stack* s) {
    stack_node* snode = s->head;
    tree* n = s->head->data;
    s->head = s->head->next;
    free(snode);
    return n;
}

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

void preorderTraversal(tree* n) {
    if (n == NULL) {
        return;
    }
    stack* s = (stack*)malloc(sizeof(stack));
    init_stack(s);
    push(s, n);
    while (s->head != NULL) {
        n = pop(s);
        printf("%d ", (int)n->data);
        if (n->right) {
            push(s, n->right);
        }
        if (n->left) {
            push(s, n->left);
        }
    }
}

int main(void) {
    tree* t;
    int i;
    init(&t);
    double a_i;
    for (i = 0; i < 7; i++) {
        scanf("%lf", &a_i);
        insert(t, a_i);
    }
    preorderTraversal(t);
    return 0;
}



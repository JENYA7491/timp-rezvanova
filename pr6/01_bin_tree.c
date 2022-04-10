#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// элемент дерева
typedef struct tree
{
    struct tree* right;
    struct tree* left;
    struct tree* parent;
    int data;
} tree;

//элемент очереди
typedef struct node
{
    void* ptr;
    struct node* next;
} node;

//структура очереди
typedef struct
{
    node* head;
    node* tail;
} queue_t;

//иниц очереди
void q_init(queue_t* q)
{
    q->head = q->tail = NULL;
}

int queue_empty(queue_t* q)
{
    return (q->head == NULL);
}

//добавление элемента
int queue_add(queue_t* q, void* ptr)
{
    node* p = (node*)malloc(sizeof(node));
    if (p != NULL)
    {
        p->ptr = ptr;
        p->next = NULL;
        if (q->head == NULL)
            q->head = q->tail = p;
        else
        {
            q->tail->next = p;
            q->tail = p;
        }
    }
    return (p != NULL);
}

//удаление элемента
void queue_remove(queue_t* q)
{
    node* t;
    if (q->head != NULL)
    {
        t = q->head;
        q->head = q->head->next;
        free(t);
        if (q->head == NULL)
            q->tail = NULL;
    }
}

void* queue_front(queue_t* q)
{
    return q->head->ptr;
}

void inorderTraversal(tree* tr)
{
    tree* node_t;
    queue_t queue_1;
    q_init(&queue_1);
    queue_add(&queue_1, tr);
    while (!queue_empty(&queue_1))
    {
        node_t = (tree*)queue_front(&queue_1);
        queue_remove(&queue_1);
        printf("%d ", (int)node_t->data);
        if (node_t->left)
            queue_add(&queue_1, node_t->left);
        if (node_t->right)
            queue_add(&queue_1, node_t->right);
    }
}

// Инициализация дерева
void t_init(tree** n)
{
    *n = (tree*)malloc(sizeof(tree));
    (*n)->right = NULL;
    (*n)->left = NULL;
    (*n)->data = 2147483647;
}

// Вставка значения в дерево
int insert(tree* n, int value)
{
    if (n->data == 2147483647)
    {
        n->data = value;
        return 0;
    }
    if (n->data == value)
        return 1;
    if (value > n->data)
    {
        if (n->right)
            return(insert(n->right, value));
        else
        {
            n->right = (tree*)malloc(sizeof(tree));
            n->right->right = NULL;
            n->right->left = NULL;
            n->right->data = value;
            return 0;
        }
    }
    else
    {
        if (n->left)
            return(insert(n->left, value));
        else
        {
            n->left = (tree*)malloc(sizeof(tree));
            n->left->right = NULL;
            n->left->left = NULL;
            n->left->data = value;
            return 0;
        }
    }
    return 2;
}

int main()
{
    tree* t;
    int i, a;
    t_init(&t);
    for (i = 0; i < 7; i++)
    {
        scanf("%d", &a);
        insert(t, a);
    }
    inorderTraversal(t);
    return 0;
}


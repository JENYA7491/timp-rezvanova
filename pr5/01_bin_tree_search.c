#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


typedef struct node
{
    struct node* right;
    struct node* left;
    double data;
} node;

void init(node** init_node)
{
    *init_node = (node*)malloc(sizeof(node));
    (*init_node)->right = NULL;
    (*init_node)->left = NULL;
    (*init_node)->data = 2147483648;
}

int insert(node* new_node, int value)
{
    if (new_node->data == 2147483648)
    {
        new_node->data = value;
        return 0;
    }
    if (new_node->data == value)
        return 1;
    if (value > (new_node->data))
    {
        if ((new_node->right) != NULL)
            return(insert(new_node->right, value));
        else
        {
            new_node->right = (node*)malloc(sizeof(node));
            new_node->right->right = NULL;
            new_node->right->left = NULL;
            new_node->right->data = value;
            return 0;
        }
    }
    else
    {
        if ((new_node->left) != NULL)
            return(insert(new_node->left, value));
        else
        {
            new_node->left = (node*)malloc(sizeof(node));
            new_node->left->right = NULL;
            new_node->left->left = NULL;
            new_node->left->data = value;
            return 0;
        }
    }
}

int remove_node(node** node_t, int value)
{
    if ((*node_t)->data == value)
    {
        if ((*node_t)->right != NULL) {
            node* Temp = (*node_t)->right, * Temp2;
            if (Temp->left != NULL)
            {
                while (Temp->left->left != NULL)
                    Temp = Temp->left;
                (*node_t)->data = Temp->left->data;
                Temp2 = Temp->left;
                Temp->left = Temp2->right;
                free(Temp2);
            }
            else
            {
                node* Temp;
                (*node_t)->data = (*node_t)->right->data;
                Temp = (*node_t)->right;
                (*node_t)->right = (*node_t)->right->right;
                free(Temp);
            }
        }
        else
        {
            node* Temp;
            Temp = (*node_t);
            (*node_t) = (*node_t)->left;
            free(Temp);
            Temp = NULL;
        }
        return 0;
    }
    else
    {
        if (value < ((*node_t)->data))
        {
            if ((*node_t)->left != NULL)
                return(remove_node(&((*node_t)->left), value));
            else
                return 1;
        }
        else
        {
            if (((*node_t)->right) != NULL)
                return(remove_node(&((*node_t)->right), value));
            else
                return 1;
        }
    }
}

void clean(node* node_t)
{
    if (node_t != NULL)
    {
        if (node_t->right != NULL)
            clean(node_t->right);
        if (node_t->left != NULL)
            clean(node_t->left);
        free(node_t);
    }
}

int find(node* node_t, int value)
{
    if (node_t->data == value)
    {
        printf("_ ");
        if (node_t->left != NULL)
            printf("%d ", (int)node_t->left->data);
        else
            printf("_ ");
        if (node_t->right != NULL)
            printf("%d", (int)node_t->right->data);
        else
            printf("_");
    }
    else
    {
        if (value < node_t->data)
        {
            if (node_t->left != NULL)
            {
                if (node_t->left->data == value)
                {
                    printf("%d ", (int)node_t->data);
                    if ((node_t->left->left) != NULL)
                        printf("%d ", (int)node_t->left->left->data);
                    else
                        printf("_ ");
                    if ((node_t->left->right) != NULL)
                        printf("%d", (int)node_t->left->right->data);
                    else
                        printf("_");
                }
                else
                    return(find(node_t->left, value));
            }
            else
                return 1;
        }
        else
        {
            if (node_t->right != NULL)
            {
                if (node_t->right->data == value)
                {
                    printf("%d ", (int)node_t->data);
                    if ((node_t->right->left) != NULL)
                        printf("%d ", (int)node_t->right->left->data);
                    else
                        printf("_ ");
                    if ((node_t->right->right) != NULL)
                        printf("%d", (int)node_t->right->right->data);
                    else
                        printf("_");
                }
                else
                    return(find(node_t->right, value));
            }
            else
                return 1;
        }
    }
    return 0;
}



int how_tall(node* node_t)
{
    int r = 0, l = 0;
    if ((node_t->right) != NULL)
        r = how_tall(node_t->right);
    if ((node_t->left) != NULL)
        l = how_tall(node_t->left);
    if (r > l)
        return (r + 1);
    return (l + 1);
}



int remove_min(node* node_t)
{
    node* Temp = node_t, * Temp2;
    if (Temp->left != NULL)
    {
        while (Temp->left->left != NULL)
            Temp = Temp->left;
        Temp2 = Temp->left;
        Temp->left = Temp2->right;
        free(Temp2);
    }
    else
    {
        Temp = node_t->right;
        free(node_t);
        node_t = Temp;
    }
    return 0;
}

int rotate_right(node** node_t)
{
    if (*node_t == NULL)
        return 1;
    node* A, * B, * C = (*node_t)->right;
    node* x = (*node_t)->left, * y = (*node_t), * Temp = (node*)malloc(sizeof(node));
    if (x != NULL)
    {
        A = x->left;
        B = x->right;
    }
    else
        return 1;
    Temp->right = y;
    Temp->left = A;
    Temp->right->right = C;
    Temp->right->left = B;
    Temp->data = x->data;
    free(x);
    (*node_t) = Temp;
    return 0;
}

int rotate_left(node** node_t)
{
    if (*node_t == NULL)
        return 1;
    node* A = (*node_t)->left;
    node* B;
    node* C;
    node* x = (*node_t);
    node* y = (*node_t)->right;
    node* Temp = (node*)malloc(sizeof(node));
    if (y != NULL)
    {
        B = y->left;
        C = y->right;
    }
    else
        return 1;
    Temp->right = C;
    Temp->left = x;
    Temp->left->right = B;
    Temp->left->left = A;
    Temp->data = y->data;
    free(y);
    (*node_t) = Temp;
    return 0;
}

int print_tree(node* node_t)
{
    if (node_t == NULL)
    {
        printf("-\n");
        return 1;
    }
    node* temp_1 = node_t;
    int level = 0, i, j, k, sk;
    int* list;
    level = how_tall(node_t);
    list = (int*)malloc(sizeof(int));
    for (i = 0; i < level; i++)
    {
        if (i != 0)
        {
            list = (int*)realloc(list, i * sizeof(int));
            for (j = 0; j < i; j++)
                list[j] = 0;
        }
        j = 1;
        sk = i;
        while (sk != 0)
        {
            j = j * 2;
            sk--;
        }
        while (j != 0)
        {
            k = 0;
            temp_1 = node_t;
            for (k = 0; k < i; k++)
            {
                if (list[k] == 0)
                {
                    if ((temp_1->left) != NULL)
                        temp_1 = temp_1->left;
                    else
                    {
                        k = -1;
                        break;
                    }
                }
                else
                {
                    if ((temp_1->right) != NULL)
                        temp_1 = temp_1->right;
                    else
                    {
                        k = -1;
                        break;
                    }
                }
            }
            if (i != 0)
            {
                sk = i - 1;
                list[sk]++;
                while (1)
                {
                    if (list[sk] == 2)
                    {
                        list[sk] = 0;
                        sk--;
                        if (sk < 0)
                            break;
                        else
                            list[sk]++;
                    }
                    else
                        break;
                }
            }
            if (k == -1)
                printf("_");
            else
                printf("%d", (int)temp_1->data);
            j--;
            if (j != 0)
                printf(" ");
        }
        printf("\n");
    }
    return 1;
}

int count_nodes(node* t)
{
    if (t == NULL)
        return 0;
    int r, l;
    l = count_nodes(t->left);
    r = count_nodes(t->right);
    return (l + r + 1);
}

int main()
{
    node* tmp;
    int i;
    double a;
    init(&tmp);
    for (i = 0; i < 4; i++)
    {
        scanf("%lf", &a);
        insert(tmp, a);
    }
    print_tree(tmp);
    printf("\n");

    for (i = 0; i < 3; i++)
    {
        scanf("%lf", &a);
        insert(tmp, a);
    }
    print_tree(tmp);
    printf("\n");
    for (i = 0; i < 2; i++)
    {
        scanf("%lf", &a);
        a = find(tmp, a);
        if (a == 1)
            printf("-");
        printf("\n\n");
    }
    scanf("%lf", &a);
    remove_node(&tmp, a);
    print_tree(tmp);
    printf("\n");
    while (1)
    {
        a = rotate_left(&tmp);
        if (a == 1)
            break;
    }
    print_tree(tmp);
    printf("\n");
    while (1)
    {
        a = rotate_right(&tmp);
        if (a == 1)
            break;
    }
    print_tree(tmp);
    printf("\n");
    printf("%d\n\n", count_nodes(tmp));
    clean(tmp);
    tmp = NULL;
    print_tree(tmp);
    return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list {
  struct node* head;
} list;

typedef struct node {
  int value;
  struct node* next;
} node;

node* create_node(int value)
{
  node* element = (node*)malloc(sizeof(node));
  element->value = value;
  element->next = NULL;
  return element;
}

void init(list* l)
{
  l->head = NULL;
}

bool is_empty(list* l)
{
    if (l->head == NULL)
        return true;
    else return false;
}

node* find(list* l, int value)
{
  if (is_empty(l))
    return NULL;

  node* node_next = l->head;
  while(node_next->value != value)
  {
    if(node_next->next == NULL)
      return NULL;
    node_next = node_next->next;
  }
  return node_next;
}

int push_back(list* l, int value)
{
    if (is_empty(l))
    {
      node* element = create_node(value);
      l->head = element;
      return 0;
    }

    node* element = l->head;
    while (element->next != NULL)
    {
      element = element->next;
    }
    node* tmp = create_node(value);
    element->next = tmp;
    return 0;
}

int push_front(list* l, int value)
{
  if (is_empty(l))
  {
    node* element = create_node(value);
    l->head = element;
    return 0;
  }

  node* element = l->head;
  node* tmp = create_node(value);
  l->head = tmp;
  tmp->next = element;
  return 0;
}

int insert_after(node* n, int value)
{
  node* node_add = create_node(value);
  node_add->next = n->next;
  n->next = node_add;
  return 0;
}

int remove_node(list* l, int value)
{
  if(is_empty(l))
    return;

  node* next = l->head;
  node* prev = NULL;

  while(next->value != value)
  {
    if(next->next == NULL)
      return 0;

    prev = next;
    next = next->next;
  }

  if(next == l->head)
    l->head = next->next;
  else
    prev->next = next->next;

  free(next);
  return 0;
}

void print(list* l)
{
    node* element = l->head;
    if (element == NULL)
    {
        printf("\n");
        return 0;
    }

    while (element != NULL)
    {
        printf("%d ", element->value);
        element = element->next;
    }
    printf("\n");
}

void clean(list* l)
{
  node* tmp;
  node* next = l->head;
  while (next)
  {
    tmp = next->next;
    free(next);
    next = tmp;
  }
  l->head = NULL;
}

int main()
{
  list l;
  int n , m, t, z, j, x, i, value, k1, k2, k3;

  scanf("%d", &n);
  init(&l);

  for (i = 1; i <= n; i++)
  {
    scanf("%d", &value);
    push_back(&l, value);
  }
  print(&l);

  scanf("%d %d %d", &k1, &k2, &k3);

  if (find(&l, k1) != NULL)
    printf("1 ");
  else
    printf("0 ");

  if (find(&l, k2) != NULL)
    printf("1 ");
  else
    printf("0 ");

  if (find(&l, k3) != NULL)
    printf("1 ");
  else
    printf("0 ");

  printf("\n");

  scanf("%d", &m);
  push_back(&l, m);
  print(&l);

  scanf("%d", &t);
  push_front(&l, t);
  print(&l);

  scanf("%d %d", &j, &x);
  node* next = l.head;
  for (i = 1; i < j; i++)
  {
    next = next->next;
  }
  insert_after(next, x);
  print(&l);

  scanf("%d", &z);
  remove_node(&l, z);
  print(&l);

  clean(&l);
  return 0;
}



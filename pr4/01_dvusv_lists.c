#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct list
{
    struct node* head;
    struct node* tail;
} list;

typedef struct node
{
    int value;
    struct node* next;
    struct node* prev;
} node;

node* create_node(int value)
{
  node* element = (node*)malloc(sizeof(node));
  element->value = value;
  element->next = NULL;
  element->prev = NULL;
  return element;
}

void init(list *l)
{
    l->head = NULL;
    l->tail = NULL;
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
  l->tail = NULL;
}

bool is_empty(list *l)
{
	if (l->head == NULL)
		return true;
	return false;
}

node* find(list *l, int value)
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

int push_back(list *l, int value)
{
	node* new_node = create_node(value);
	if (is_empty(l))
	{
		l->head = new_node;
    l->tail = new_node;
    return 0;
	}

  node* tmp = l->tail;

  tmp->next = new_node;
  new_node->prev = tmp;
  new_node->next = NULL;
  l->tail = new_node;
  return 0;
}

int push_front(list *l, int value)
{
  node* new_node = create_node(value);
  if (is_empty(l)) {
    l->head = new_node;
    l->tail = new_node;
    return 0;
  }

  node* tmp = l->head;
  new_node->next = tmp;
  tmp->prev = new_node;
  l->head = new_node;

  return 0;
}

int insert_after(list*l, node *n, int value )
{
  if (n == l->tail) {
    node* new_node = create_node(value);
    n->next = new_node;
    new_node->prev = n;
    l->tail = new_node;
    return 0;
  }

  node* new_node = create_node(value);
  new_node->next = n->next;
  n->next->prev = new_node;
  new_node->prev = n;
  n->next = new_node;
  return 0;
}

int insert_before(list* l, node *n, int value)
{
  if (n->prev == NULL) {
    node* new_node = create_node(value);
    l->head = new_node;
    n->prev = new_node;
    new_node->next = n;
    return 0;
  }

  node* new_node = create_node(value);
  node* tmp = n->prev;
  tmp->next = new_node;
  new_node->next = n;
  new_node->prev = tmp;
  n->prev = new_node;
  return 0;

}

int remove_first(list *l, int value)
{
  if (is_empty(l))
    return 0;

  node* tmp = l->head;

  while (tmp->value != value) {
    if (tmp == l->tail)
      return 0;

    tmp = tmp->next;
  }

  if (tmp == l->head) {
    l->head = tmp->next;
    tmp->next->prev = l->head;
  }
  else {
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
  }

  free(tmp);
  return 0;
}

int remove_last(list *l, int value)
{
  if (l->tail == NULL)
        return 1;
	node* temp = l->tail;
	while (temp->value != value)
	{
		if (temp->prev == NULL)
		{
			return 1;
		}
		temp = temp->prev;
	}
	if (temp == l->head)
	{
		temp->next->prev = NULL;
		l->head = temp->next;
	}
	else if (temp == l->tail)
	{
		temp->prev->next = NULL;
		l->tail = temp->prev;
	}
	else
	{
		temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
	}
	free(temp);
  return 0;
}

void print(list *l)
{
	node* next_el = l->head;
	while (next_el != NULL)
    {
        printf("%d ", next_el->value);
        next_el = next_el->next;
    }
    printf("\n");
}

void print_invers(list *l)
{
	node* next_el = l->tail;
	while (next_el != NULL)
    {
        printf("%d ", next_el->value);
        next_el = next_el->prev;
    }
    printf("\n");
}

int main()
{
	list l;
  int i, n, value, k, m, t, j, x, u, y, z, r;

  scanf("%d", &n);
  init(&l);

  for (i = 1; i <= n; i++)
  {
    scanf("%d", &value);
    push_back(&l, value);
  }
  print(&l);

  for (i = 0; i < 3; i++) {
    scanf("%d", &k);
    if (find(&l, k) != NULL)
      printf("1 ");
    else
      printf("0 ");
  }

  printf("\n");

  scanf("%d", &m);
  push_back(&l, m);
  print_invers(&l);

  scanf("%d", &m);
  push_front(&l, m);
  print(&l);

  scanf("%d", &j);
  scanf("%d", &x);
  node* tmp = l.head;
  for ( i = 1; i < j; i++) {
    tmp = tmp->next;
  }

  insert_after(&l, tmp, x);
  print_invers(&l);

  scanf("%d", &u);
  scanf("%d", &y);
  tmp = l.head;
  for ( i = 1; i < u; i++) {
    tmp = tmp->next;
  }
  insert_before(&l, tmp, y);
  print(&l);

  scanf("%d", &z);
  remove_first(&l, z);
  print_invers(&l);

  scanf("%d", &r);
  remove_last(&l, r);
  print(&l);

  clean(&l);

  return 0;
}




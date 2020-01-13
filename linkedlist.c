#include "stdio.h"
#include "stdlib.h"

struct linkedlist
{
    int data;
    struct linkedlist *next_node_addr;
} * node;

struct linkedlist *first_node, *last_node;
int create_node(int);
struct linkedlist *alloc_node();
void print_node(struct linkedlist *node);
void allocate_init();

int main()
{
    int x;
    printf("Enter a number to store in the list.\n");
    scanf("%d", &x);
    allocate_init();
    if (create_node(x))
    {
        print_node(first_node);
        print_node(last_node);
    }
    printf("Done.");
    getchar();
}

int create_node(int data)
{
    node = alloc_node();
    node->data = data;
    node->next_node_addr = NULL;
    if (first_node->next_node_addr == NULL)
    {
        first_node->next_node_addr = last_node->next_node_addr = node;
        first_node->data = last_node->data = node->data;
    }
    return node != NULL;
}

void allocate_init()
{
    first_node = alloc_node();
    first_node->next_node_addr = NULL;
    last_node = alloc_node();
    last_node->next_node_addr = NULL;
}

struct linkedlist *alloc_node()
{
    return (struct linkedlist *)malloc(sizeof(struct linkedlist *));
}

void print_node(struct linkedlist *node)
{
    printf("The data inside the node is %d", node->data);
}
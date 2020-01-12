#include "stdio.h"

struct linkedlist
{
    int data;
    struct linkedlist *next;
} * node;

void print_node(struct linkedlist *node);

int main()
{
    printf("Enter a number to store in the list.");
    node = (struct linkedlist *)malloc(sizeof(struct linkedlist *));
    node->data = 24;
    node->next = NULL;
    print_node(node);
    getchar();
}

void print_node(struct linkedlist *node)
{
    printf("The data inside the default node is %d", node->data);
}
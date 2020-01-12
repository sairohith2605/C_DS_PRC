#include "stdio.h"

void display();

int main()
{
    printf("Hello");
    display();
    getchar();
}

void display()
{
    int b = 2098;
    int *a = &b;
    *a = *a + 64;

    printf("%d", b);
}
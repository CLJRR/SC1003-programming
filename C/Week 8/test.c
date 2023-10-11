#include <stdio.h>
int main()
{
    int test = 0;
    while (test != -1)
    {
        printf("enter number: ");
        scanf("%d", &test);
        if (test == 1)
        {
            printf("True\n");
        }
        else
        {
            printf("False\n");
        }
        printf("Hello world");
    }
}
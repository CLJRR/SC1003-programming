// #include <stdio.h>
// int main()
// {
//     int id, mark;

//     do
//     {
//         switch (mark)
//         {
//         case 75 ... 100:
//             printf("Grade = A\n");
//             break;
//         case 65 ... 74:
//             printf("Grade = B\n");
//             break;
//         case 55 ... 64:
//             printf("Grade = C\n");
//             break;
//         case 45 ... 54:
//             printf("Grade = D\n");
//             break;
//         default:
//             printf("Grade = F\n");
//             break;
//         }
//         printf("Enter Student ID:\n");
//         scanf("%d", &id);
//         printf("Enter Mark:\n");
//         scanf("%d", &mark);
//     } while (id != -1);
// }
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{

    int value;
    struct node *next;

} node;

int main()
{

    // ensure proper usage

    // create list variable
    int count;
    scanf("%d", &count);
    node *list = NULL;
    // create linked list based of on no of argc
    for (int i = 0; i < count; i++)
    {
        // allocate memory for node and check for enough memory
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("not enough memory");
            return 1;
        }
        // save argv into value
        n->value = 1;
        // change next node's address to NULL
        n->next = NULL;

        n->next = list;
        list = n;
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
    ptr = list;

    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return 0;
}
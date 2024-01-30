#include <stdio.h>
// #include <stdlib.h>
// typedef struct node
// {
//     char name[30];
//     int age;
//     struct node *next;
// } node;

// int main(void)
// {
//     node *list = NULL;
//     int count;
//     printf("please enter number of people:\n");
//     scanf("%d", &count);
//     for (int i = 0; i < count; i++)
//     {
//         node *n = malloc(sizeof(node));

//         printf("Please enter name:  ");
//         scanf("%s", &n->name);
//         printf("please enter age");
//         scanf("%d", &n->age);
//         n->next = NULL;
//         n->next = list;
//         list = n;
//     }
//     node *v = list;

//     while (v != NULL)
//     {
//         printf("%s  ", v->name);
//         printf("%d\n", v->age);
//         v = v->next;
//     }
// }
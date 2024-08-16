#include <stdio.h>

// This shows 2 ways to do it

// int main()
// {
//     int input;
//     printf("Enter the height:\n");
//     scanf("%d", &input);
//     printf("Pattern:\n");
//     for (int i = 1; i <= input; i++)
//     {
//         switch (i % 3)
//         {
//         case 1:
//             for (int j = 1; j <= i; j++)
//             {
//                 printf("1");
//             }
//             printf("\n");
//             break;
//         case 2:
//             for (int j = 1; j <= i; j++)
//             {
//                 printf("2");
//             }
//             printf("\n");
//             break;
//         default:
//             for (int j = 1; j <= i; j++)
//             {
//                 printf("3");
//             }
//             printf("\n");
//             break;
//         }
//     }
// }
int main()
{
    int input;
    printf("Enter the height:\n");
    scanf("%d", &input);
    printf("Pattern:\n");
    for (int i = 1; i <= input; i++)
    {
        int number = (i % 3);
        if (number == 0)
            number = 3;
        for (int j = 1; j <= i; j++)
        {
            printf("%d", number);
        }
        printf("\n");
    }
}
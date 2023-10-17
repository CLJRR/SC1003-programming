#include <stdio.h>

// int main(void)
// {
//     int height, width;
//     printf("Enter Height and Width:");
//     scanf("%d %d", &height, &width);
//     for (int i = 0; i < width; i++)
//     {
//         printf("=");
//     }
//     printf("\n");
//     for (int i = 0; i < height - 2; i++)
//     {
//         printf("*");
//         for (int j = 0; j < width - 2; j++)
//         {
//             printf(" ");
//         }
//         printf("*\n");
//     }
//     for (int i = 0; i < width; i++)
//     {
//         printf("=");
//     }
//     printf("\n");
//     // }

//     // int main(void)
//     // {
//     //     int height;
//     //     printf("Please enter height");
//     //     scanf("%d", &height);
//     for (int i = 1; i <= height; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             printf("%d", i);
//         }
//         printf("\n");
//     }
//     // }
//     // int main(void)
//     // {
//     // int height;
//     // printf("Please enter height: ");
//     // scanf("%d", &height);
//     for (int i = 1; i <= height; i++)
//     {
//         for (int j = 1; j <= height - i; j++)
//         {
//             printf(" ");
//         }
//         for (int k = 0; k < i; k++)
//         {
//             printf("%d", i);
//         }
//         printf("\n");
//     }
// }
int main(void)
{
    int height, num;
    printf("Enter height: ");
    scanf("%d", &height);
    num = 1;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < num; k++)
        {
            printf("*", i);
        }
        num += 2;
        printf("\n");
    }
}
#include <stdio.h>
int main()
{
    int id, mark;

    do
    {
        switch (mark)
        {
        case 75 ... 100:
            printf("Grade = A\n");
            break;
        case 65 ... 74:
            printf("Grade = B\n");
            break;
        case 55 ... 64:
            printf("Grade = C\n");
            break;
        case 45 ... 54:
            printf("Grade = D\n");
            break;
        default:
            printf("Grade = F\n");
            break;
        }
        printf("Enter Student ID:\n");
        scanf("%d", &id);
        printf("Enter Mark:\n");
        scanf("%d", &mark);
    } while (id != -1);
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int studentNumber = 0;
    int mark;
    printf("please enter student number: ");
    scanf("%d", &studentNumber);

    while (studentNumber != -1)
    {
        printf("Enter mark: ");
        scanf("%d", &mark);
        if (mark >= 75)
        {
            printf("grade A\n");
        }
        else if (mark >= 65)
        {
            printf("grade B\n");
        }
        else if (mark >= 55)
        {
            printf("grade C\n");
        }
        else if (mark >= 45)
        {
            printf("grade D\n");
        }
        else
        {
            printf("grade F\n");
        }
        printf("please enter student number: ");
        scanf("%d", &studentNumber);
    }
    return 0;
}

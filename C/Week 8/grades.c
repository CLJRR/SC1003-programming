#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int id, marks;
    printf("Enter Student ID:  \n");
    scanf("%d", &id);
    while (id != -1)
    {
        printf("Enter Mark:\n");
        scanf("%d", &marks);
        if (marks >= 75)
        {
            printf("Grade = A\n");
        }
        else if (marks >= 65)
        {
            printf("Grade = B\n");
        }
        else if (marks >= 55)
        {
            printf("Grade = C\n");
        }
        else if (marks >= 45)
        {
            printf("Grade = D\n");
        }
        else
        {
            printf("Grade = F\n");
        }
        printf("Enter Student ID:  \n");
        scanf("%d", &id);
    }
}

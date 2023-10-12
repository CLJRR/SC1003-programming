#include <stdio.h>
int main()
{
    float average;
    int count, num, numCount;
    printf("Enter number of lines:\n");
    scanf("%d", &count);
    for (int i = 1; i <= count; i++)
    {
        average = numCount = num = 0;
        printf("Enter line %d (end with -1):\n", i);
        scanf("%d", &num);
        while (num != -1)
        {
            average += num;
            numCount++;
            scanf("%d", &num);
        }
        printf("Average = %.2f\n", (float)average / (numCount));
    }
}
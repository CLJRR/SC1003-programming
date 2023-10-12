#include <stdio.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int main()
{
    int number, digit, result = 0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("Enter the digit: \n");
    scanf("%d", &digit);
    printf("digitPos1(): %d\n", digitPos1(number, digit));
    // digitPos2(number, digit, &result);
    // printf("digitPos2(): %d\n", result);
    return 0;
}
int digitPos1(int num, int digit)
{
    for (int i = 1; i <= digit - 1; i++)
    {
        num /= 10;
    }
    num %= 10;
    return num;
}
void digitPos2(int num, int digit, int *result)
{
    for (int i = 1; i <= digit - 1; i++)
    {
        num /= 10;
    }
    num %= 10;
    *result = num;
}
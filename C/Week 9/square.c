#include <stdio.h>
int square1(int num);
void square2(int num, int *result);
int main()
{
    int number, result = 0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("square1(): %d\n", square1(number));
    square2(number, &result);
    printf("square2(): %d\n", result);
    return 0;
}
int square1(int num)
{
    int out = 0, adder = 1;
    for (int i = 1; i <= num; i++)
    {
        out += adder;
        adder += 2;
    }
    return out;
}
void square2(int num, int *result)
{
    int out = 0, adder = 1;
    for (int i = 1; i <= num; i++)
    {
        out += adder;
        adder += 2;
    }
    *result = out;
}
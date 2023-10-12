#include <stdio.h>
int main()
{
    float x, output = 1, numerator = 1;
    int denominator = 1;
    printf("Enter x:\n");
    scanf("%f", &x);
    for (int i = 1; i <= 10; i++)
    {
        denominator *= i;
        numerator *= (float)x;
        output += ((float)numerator / denominator);
    }
    printf("Result = %.2f", output);
}
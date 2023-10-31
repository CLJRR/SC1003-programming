// #include <stdio.h>
// #include <math.h>

// double sinc(double x)
// {
//     if (x == 0)
//         return 1;
//     else
//         return sin(x) / x;
// }

// int main(void)
// {
//     double lower, upper, x, interval;

//     printf("Enter endpoints a and b (a < b); e.g. -5 5: ");
//     scanf("%lf %lf", &upper, &lower);

//     printf("x       sinc(x)\n");
//     interval = (upper - lower) / 20.0;
//     for (int counter = 0; counter <= 20; counter++)
//     {
//         x = lower + counter * interval;
//         printf("%.2f  %f\n", x, sinc(x));
//     }
//     return 0;
// }
#include <stdio.h>
#include <math.h>

double sinc(double x)
{
    if (x == 0)
        return 1;
    else
        return sin(x) / x;
}

int main(void)
{
    double lower, upper, x, interval;

    printf("Enter endpoints a and b (a < b); e.g. -5 5: ");
    scanf("%lf %lf", &upper, &lower);

    printf("x       sinc(x)\n");
    interval = (upper - lower) / 20;
    for (int counter = 0; counter <= 20; counter++)
    {
        x = lower + counter * interval;
        printf("%f  %f", x, sinc(x));
    }
    return 0;
}
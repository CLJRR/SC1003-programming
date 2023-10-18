#include <stdio.h>
int main()
{
    // char ch = '!';
    // printf("%d", ch);
    // printf("%d %c\n%d %c", ch, ch, ch2, ch2);
    for (int i = 40; i <= 49; i++)
    {
        printf("%c ", i);
    }
    for (int i = 50; i <= 119; i++)
    {

        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%c ", i);
    }
    // printf("%c", (ch - 32));
}
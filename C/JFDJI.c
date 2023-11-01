#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll_dice(void)
{
    return rand() % 6 + 1; // Returns a random number between 1 and 6
}
int main(void)
{
    int uscore, cscore;
    int user_sixes = 0, comps_sixes = 0;
    int user_evens = 0, comp_evens = 0;
    int utotal, comp_total = 0;
    srand(time(NULL)); // Seed for random number generation
    printf("Users turn to roll...\n");
    printf("Hit \"Enter\" to roll the dice\n");
    for (int i = 0; i < 6; i++)
    {
        getchar();
        uscore = roll_dice();
        printf("Score: %d\n", uscore);
        if (uscore == 6)
        {
            user_sixes++;
        }
        if (uscore % 2 == 0)
        {
            user_evens++;
        }
        utotal = uscore + utotal;
    }
    printf("Computer's turn to roll...\n");
    for (int i = 0; i < 6; i++)
    {
        cscore = roll_dice();
        printf("Score: %d\n", cscore);
        if (cscore == 6)
        {
            comps_sixes++;
        }
        if (cscore % 2 == 0)
        {
            comp_evens++;
        }
        comp_total += cscore;
    }
    if (user_sixes >= 3)
    {
        printf("Congratulations! User wins.\n");
    }
    else if (comps_sixes >= 3)
    {
        printf("Sorry! Computer wins.\n");
    }
    else
    {
        if (user_evens > comp_evens)
        {
            printf("Congratulations! User wins.\n");
        }
        else if (user_evens < comp_evens)
        {
            printf("Sorry! Computer wins.\n");
        }
        else
        {
            if (utotal > comp_total)
            {
                printf("Congratulations! User wins.\n");
            }
            else if (utotal < comp_total)
            {
                printf("Sorry! Computer wins.\n");
            }
            else
            {
                printf("It's a draw!\n");
            }
        }
    }

    return 0;
}
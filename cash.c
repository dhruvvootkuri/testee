#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed:");
    }
    while (dollars < 0 || dollars == 0);
    int cents = round(dollars * 100);
    int coins = 0;
    do
    {
        if (cents > 25 || cents == 25)
        {
            coins++;
            cents = cents - 25;

        }
        else if (cents > 10 || cents == 10)
        {
            coins++;
            cents = cents - 10;

        }
        else if (cents > 5 || cents == 5)
        {
            coins++;
            cents = cents - 5;

        }
        else if (cents > 1 || cents ==1)
        {
            coins++;
            cents = cents - 1;

        }
    }
    while (cents > 0);
    printf("%d\n",coins);
}
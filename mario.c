//This is similar to mario.c/less, but instead, it builds an iscoceles triangle based on the given height.

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //creates variable
    int height;

    do
    {
        //gets user input
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); //conditional statements foe height requirements
    for (int i = 1; i < height + 1; i++) //for every line...
    {
        for (int b = height; b > i; b--) //prints the spaces that come before the asterisk(s)
        {
            printf(" ");
        }
        for (int a = 1; a < i + 1; a++) //prints the asterisk(s)
        {
            printf("#");
        }
        printf("  "); //Keeps a space in between the pyramids (spaces out every line)
        for (int c = 1; c < i + 1; c++) //prints the asterisk(s) (again, but with no spaces to back them up a specific way)
        {
            printf("#");
        }
        printf("\n"); //new line
    }

}

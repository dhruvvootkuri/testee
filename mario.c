#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int height;
    do
        {
            height = get_int("Height: ");
        }
        while (height<1 || height>8);
    for (int i = 1; i<height+1; i++)
    {
        for(int b=height; b>i;b--)
        {
            printf(" ");
        }
        for(int a=1; a<i+1;a++)
        {
            printf("#");
        }
        printf("\n");
    }

}

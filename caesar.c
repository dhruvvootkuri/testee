#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //char str[] = "strtok needs to be called several times to split a string";
    int x = 0;

    if (argc<=1)
    {
        printf("Usage: ./caesar key\n");
        x++;
    }

    if (argc > 2 && x==0)
    {
        printf("Usage: ./caesar key\n");
        x++;
    }
    if (argc==2)
    {
        for (int i=0;i<strlen(argv[1]);i++)
        {
            if( ( (argv[1][i]>='a' && argv[1][i]<='z') || (argv[1][i]>='A' && argv[1][i]<='Z') ) && x==0)
            {

                printf("Usage: ./caesar key\n");
                x++;
            }
        }
        if (x==0)
        {
            int key = atoi(argv[1]);
        }
    }
    if (x==0)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        for (int j=0;j<strlen(plaintext);j++)
        {
            char c = plaintext[j];
            if (isalpha(c))
            {
                if (isupper(c))
                {
                    c = c - 64;
                    c = (c+key)%26;
                    c = c + 64;
                }
                else if (islower(c))
                {
                    c = c - 96;
                    c = (c+key)%26;
                    c = c + 96;
                }
            }
            plaintext[j] = c;
        }
    printf("%s\n",plaintext);
    }
}
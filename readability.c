#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int j;
    string read;
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int index;
    do
    {
        read = get_string("Text:");
        j = strlen(read);
    }
    while (j<=0);

    for (int i=0 ; i<j ; i++)
    {
        if((read[i]>='a' && read[i]<='z') || (read[i]>='A' && read[i]<='Z'))
        {
            letters++;

        }
        else if (read[i] == ' ')
        {
            if((read[i+1]>='a' && read[i+1]<='z') || (read[i+1]>='A' && read[i+1]<='Z'))
                words++;
        }
        else if (read[i] == '.' || read[i] == '!' || read[i] == '?')
        {
            sentences++;
        }
    }
    words++;
    letters = letters *100/words;
    sentences = sentences * 100/words;
    index = 0.0588 * letters - 0.296 * sentences - 15.8 + 1;
    if (index>=1 && index<=16)
    {
        printf("Grade %d\n",index);
    }
    else if (index<1)
    {
        printf("Before Grade 1 \n");
    }
    else
    {
        printf("Grade 16+ \n");
    }
}
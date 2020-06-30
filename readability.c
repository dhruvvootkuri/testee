#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int j;
    string read;
    float letters = 0;
    int words = 0;
    float sentences = 0;
    float index = 0.0;
    int rindex;
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
            printf("Letter found in %d\n",i);
            letters++;

        }
        else if (read[i] == ' ')
        {
            printf("Space found in %d\n",i);
            if((read[i+1]>='a' && read[i+1]<='z') || (read[i+1]>='A' && read[i+1]<='Z'))
                words++;
        }
        else if (read[i] == '.' || read[i] == '!' || read[i] == '?')
        {
            printf("Punctuation found in %d\n",i);
            sentences++;
        }
    }
    words++;

    printf("%f\n",letters);
    printf("%f\n",sentences);
    printf("%d\n",words);

    letters = letters *100/words;
    sentences = sentences * 100/words;

    printf("%f\n",letters);
    printf("%f\n",sentences);

    //letters = round(letters);
    //sentences = round(sentences);

    printf("%f\n",letters);
    printf("%f\n",sentences);

    rindex = (int)index;

    index = 0.0588 * letters - 0.296 * sentences - 15.8;
    index = round(index);
    if (index>=1 && index<=16)
    {
        printf("Grade %f\n",index);
    }
    else if (index<1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
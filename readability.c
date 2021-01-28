//This program is used to analyze any text to decide what grade level it is for.

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
    float sentences = 0; //these are used in my formula at the end.  The hardest part was to get these numbers.
    float index = 0.0;
    int rindex;
    do
    {
        read = get_string("Text:"); //input was here
        j = strlen(read); //j is th number of characters in read
    }
    while (j<=0);
    for (int i=0 ; i<j ; i++) //this loops over every character in our text
    {
        if((read[i]>='a' && read[i]<='z') || (read[i]>='A' && read[i]<='Z')) //This checks if the characteri is a letter
        {

            letters++;

        }
        else if (read[i] == ' ') //Checks if the character is a space
        {

            if((read[i+1]>='a' && read[i+1]<='z') || (read[i+1]>='A' && read[i+1]<='Z')) //Checks if the character after that is a letter, because we don't want to count double spaces.
                words++;
        }
        else if (read[i] == '.' || read[i] == '!' || read[i] == '?') //Checs if the character is a puncuation mark
        {

            sentences++;
        }
    }
    words++;



    letters = letters *100/words;  //This is where our formula is made.
    sentences = sentences * 100/words;


    //letters = round(letters);
    //sentences = round(sentences);


    index = 0.0588 * letters - 0.296 * sentences - 15.8;
    index = round(index);
    if (index>=1 && index<=16)
    {
        printf("Grade %d\n",(int)index);
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

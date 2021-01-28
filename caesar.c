//This program is used to cipher text.  The user will input a key(int) and a plaintext(str). 
//The code then changes every letter in the plaintext by they key.  For example, if we had the key 1 and plaintext "Hello",
//then our ciphertext will be "Ifmmp" because 1 past H is I, 1 past e is f, 1 past l is m, and 1 past o is p!

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]) //two arguments, the number of arguements and the array of arguments called
{
    //char str[] = "strtok needs to be called several times to split a string";
    int x = 0;
    
    //argc is the number of arguments given when file is called
    
    if (argc <= 1) //If there are less than 2 arguments, the file being called and the key, then it is incorrect usage
    {
        printf("Usage: ./caesar key\n");
        x++;
        return 1;
    }

    if (argc > 2 && x == 0) //checks if too many arguments are given
    {
        printf("Usage: ./caesar key\n");
        x++; 
        return 1;
    }
    if (argc == 2) //checks if it has any letters in it
    {
        for (int i = 0; i < strlen(argv[1]); i++) //references every character in the key
        {
            if (((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z')) && x == 0) //checks if it is a number
            {

                printf("Usage: ./caesar key\n");
                x++; //Only if x is 0 will we continue the code, meaning it will only run unless all of the characters in the key are numbers
                return 1;
            }
        }
        if (x == 0)
        {
            int key = atoi(argv[1]); //we just want to convert our key to an integer as we move forward so we can call certain functions to it that cannot be called on a string
        }
    }
    if (x == 0)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: "); //Now, we are receiving input for our plaintext,aka the message that needs to be ciphered
        for (int j = 0; j < strlen(plaintext); j++) //For every letter in our text...
        {
            char c = plaintext[j]; //c is our character that is currently being referenced
            if (isalpha(c)) //for all letters
            {
                if (isupper(c)) //for all uppercase letters
                {
                    c = c - 64;
                    c = (c + key) % 26;
                    c = c + 64;
                }
                else if (islower(c)) //for all lowercase letters
                {
                    c = c - 96;
                    c = (c + key) % 26;
                    c = c + 96;
                }
                //non-letters are not changed
            }
            plaintext[j] = c; //changes every character in plaintext 1 by 1
        }
        printf("ciphertext: %s\n", plaintext); // gives us the output now that every character from plaintext has been changed
    }
}

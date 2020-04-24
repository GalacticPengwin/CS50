#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//intiate main with cmd line prompt
int main(int argc, string argv[])
{
    int c;
    string text, key;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        // check char is alpha and if repeated
        for (c = 0; argv[1][c] != '\0'; c++)
        {
            //check if alpha
            int i;
            if (isalpha(argv[1][c]) != 0)
            {
                //if alpha, check if repeated
                for (i = c + 1; argv[1][i] != '\0'; i++)
                {
                    //if char is repeated, terminate
                    if (argv[1][c] == argv[1][i])
                    {
                        printf("Key must contain 26 non-repeating alphabetic characters.\n");
                        return 1;
                    }
                }
            }
            //return 1 if not alpha
            else
            {
                printf("Key must contain alphabetic characters.\n");
                return 1;
            }
        }
        key = argv[1];
        text = get_string("plaintext: ");
    }
    printf("ciphertext: ");
    // iterate through char in text
    for (c = 0; text[c] != '\0'; c++)
    {
        // if char is upper, minus 65 and find the corresponding char in key
        if (isupper(text[c]) != 0)
        {
            // convert to upper
            printf("%c", toupper(key[text[c] - 65]));
        }
        else if (islower(text[c]) != 0)
        {
            printf("%c", tolower(key[text[c] - 97]));
        }
        else
        {
            printf("%c", text[c]);
        }
    }
    printf("\n");
    return 0;
}
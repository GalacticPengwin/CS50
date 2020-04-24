#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

//intiate main with cmd line prompt
int main(int argc, string argv[])
{
    int c, key;
    string text;
    // 1. check if cmd line argument is a single line argument
    if (argc != 2)
    {
        // 1. not present printf error message, main returns 1
        printf("Error. Please input single key as command line argument\n");
        return 1;
    }
    // 2. check if cmd line argument consist of digits only
    else
    {
        for (c = 0; argv[1][c] != '\0'; c++)
        {
            //  1. not, printf Usage: ./caesar key, main returns 1
            if (isdigit(argv[1][c]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }

        }
        // 3. convert argv into int
        key = atoi(argv[1]);
    }
    // 4. prompt user for plaintext
    text = get_string("plaintext: ");
    // 5. iterate over each character in plain text
    printf("ciphertext: ");
    for (c = 0; text[c] != '\0'; c++)
    {
        //     1. if upper case, rotate, preserve case print
        if (isupper(text[c]) != 0)
        {
            printf("%c", (text[c] - 65 + key) % 26 + 65);
        }
        //     2. if lower case, rotate, preserve case print
        else if (islower(text[c]) != 0)
        {
            printf("%c", (text[c] - 97 + key) % 26 + 97);
        }
        else
        {
            //     3. else print as is
            printf("%c", text[c]);
        }
    }
    // 6. print new line
    printf("\n");
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declare variables
    int height, i, j, k, l;
    
    // prompt user for input as var height
    do
    {
        height = get_int("Height ");
    }
    while (height < 1 || height > 8); // if 1 <= height <= 8, continue, else, repeat step 1 
    
    // iterate i through to height
    for (i = 0; i < height; i++)
    {
        //on iteration i print height - i spaces
        for (j = height - 1; j > i; j--)
        {
            printf(" ");
        }
        // on iteration i print i hashes 
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }
        // followed by 1 space
        printf("  ");
        // on iteration i print i hashes 
        for (l = 0; l <= j; l++)
        {
            printf("#");
        }
        // followed by new line
        printf("\n");
    }
}

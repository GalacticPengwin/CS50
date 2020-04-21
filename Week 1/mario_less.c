#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declare variables
    int height, i, j, k;
    
    //a do while loop to initiate first prompt followed by while condition to repeat if height < 1 or height > 8
    do
    {
        //prompts user for height
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // iterate from 1 through height
    for (i = 0; i < height; i += 1)
    {
        // on iteration i, print (height-i) spaces
        for (k = height - 1; k > i; k -= 1)
        {
            printf(" ");
        }
        
        // on iteration i, then print i hashes and then a new line
        for (j = 0; j < i; j += 1)
        {
            printf("#");
        }
        
        printf("#\n");
    }
}

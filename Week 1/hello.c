#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    //asks user for their name which will be saved as string variable name
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int coins = 0, quarter = 25, dime = 10, nickel = 5, penny = 1;
    // ask user's input for change owed, repeat if change is smaller than 0
    do
    {
        change = get_float("Change owed: ");
    }    
    while (change < 0);
    // convert change owed to cents
    int cents = round(change * 100);
    
    coins = (cents / quarter) + (cents % quarter / dime) + (cents % quarter % dime / nickel) + (cents % quarter % dime % nickel);
       
    printf("%i\n", coins);

}

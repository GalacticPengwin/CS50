#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool checksum(int length, long number);

int main(void)
{
    // declare variables
    int front, n = 0;
    // prompts user for cc number
    long number = get_long("Number: ");
    // find the length n of the number
    while ((pow(10, n)) < number)
    {
        n++;
    }
    // find the front 2 digits of the number
    front = (number / (long)pow(10, (n - 2)));
    // check if AMEX and if checksum returns true
    if (n == 15 && (front == 34 || front == 37) && checksum(n, number))
    {
        printf("AMEX\n");
    }
    // check if Mastercard and if checksum returns true
    else if (n == 16 && ((51 <= front) && (front <= 55)) && checksum(n, number))
    {
        printf("MASTERCARD\n");
    }
    // check if VISA and if checksum returns true
    else if ((n == 13 || n == 16) && ((40 <= front) && (front <= 49)) && checksum(n, number))
    {
        printf("VISA\n");
    }
    // otherwise invalid
    else
    {
        printf("INVALID\n");
    }
          
}

// define checksum function which takes in number and length and returns true or false
bool checksum(int length, long number)
{
    // define var
    int i, j, even, sumodd = 0, sumeven = 0;
    // iterating through the odd numbers to the length
    for (i = 1; i <= length; i += 2)
    {
        // to get ith digit, find the modulus of number by 10^(i) {returns remainder} divided by 10^(i-1) {returns quotient}
        // sum the value of the iterations
        sumodd += (number % (long)pow(10, i)) / (long)pow(10, (i - 1)); 
    }
    // iterating through the even numbers to the length
    for (j = 2; j <= length; j += 2)
    {
        // to get 2* ith digit, (find the modulus of number by 10^(i) {returns remainder} divided by 10^(i-1) {returns quotient}) *2
        even = 2 * ((number % (long)pow(10, j)) / (long)pow(10, (j - 1)));
        // check if i iteration * 2 is larger than 9, 
        if (even > 9)
        {
            // if i iteration larger than 9, add first digit
            even = (even / 10 + even % 10);
        }
        sumeven += even;
    }
    //check if last digit of sumeven + sumodd is 0, return true
    if ((sumeven + sumodd) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

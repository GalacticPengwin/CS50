#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

long count_words(string text);
long count_letters(string text);
long count_sentences(string text);


int main(void)
{
    // getting text input from user
    string text = get_string("Text: ");
    // finding L by dividing letters over words * 100
    float L = ((double)count_letters(text) / (double)count_words(text)) * 100;
    // finding s by dividing sentence over words * 100
    float S = ((double)count_sentences(text) / (double)count_words(text)) * 100;
    float index = ((0.0588 * L) - (0.296 * S) - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}

// define function of count_words
long count_words(string text)
{
    // defining variables
    int c;
    long count = 0;

    // iterating over each character in text
    for (c = 0; text[c] != '\0'; c++)
    {
        // count number of spaces within the text
        if (isspace(text[c]) != 0)
        {
            count++;
        }
    }
    // returns the word count, assuming each word is separated by space, and text has no space front/end
    return count + 1;
}

// define fn of count_letters
long count_letters(string text)
{
    int c;
    long count = 0;

    // iterating over each char
    for (c = 0; text[c] != '\0'; c++)
    {
        // count number of alphabets
        if (isalpha(text[c]) == 0)
        {
            continue;
        }
        count++;
    }
    return count;
}

// define fn of count_sentence
long count_sentences(string text)
{
    int c;
    long count = 0;

    // iterating over each char
    for (c = 0; text[c] != '\0'; c++)
    {
        // count number of sentence, assuming eah separated by .!?
        if (text[c] == '.' || text[c] == '!' || text[c] == '?')
        {
            count++;
        }
    }
    return count;
}
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    //get input string from user
    string text = get_string("Text: ");

    //calculate the index value according to coleman-liau index
    //remember to typecast the value first to float for more precise calculation
    float L = ((float) count_letters(text) / (float) count_words(text)) * 100;
    float S = ((float) count_sentences(text) / (float) count_words(text)) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // create condition, if index > 16, print Grade 16+
    // if its < 1, print Before Grade 1
    // else, print Grade x where x = rounded index
    if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

//function to count letters
int count_letters(string text)
{
    //initialize the count variable
    int count = 0;

    //iterate through the null value of string array
    for (int i = 0; text[i] != '\0'; i++)
    {
        //check whether the input is an alphabet or not
        if (isupper(text[i]) || islower(text[i]))
        {
            //if it is an alphabeth, +1 to count
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    //initialize the first count value to 1
    //the condition of a words is at least it consist of 1 letter, therefore we set the count value to 1
    //each words in a sentence is seperated by space
    int count = 1;

    //this checks whether our text consist only space
    //if it is, set the words count to 0
    if (text[0] != '\0' && isblank(text[0]))
    {
        count = 0;
    }

    // iterate through the null value of string array
    for (int i = 0; text[i] != '\0'; i++)
    {
        //set the counter to 0
        int sum = 0;

        //this will see the value of current array + array before
        sum = text[i - 1] + text[i];

        //we are checking if our current array is a blank space or not
        /*if the sum is more than 32 and it is a blank,
        means that we are indeed dealing with a word, since if its only a space, the sum will be <= 32*/
        if (isblank(text[i]) && sum > 32)
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    //set couner to 0
    int count = 0;

    // iterate through the null value of string array
    for (int i = 0; text[i] != '\0'; i++)
    {
        //check whether our current array is a punctuation or not
        //a sentence will be counted if the word is ended with '!' or '.' or '?'
        if (ispunct(text[i]) && (text[i] == 33 || text[i] == 46 || text[i] == 63))
        {
            count++;
        }
    }
    return count;
}
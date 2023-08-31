#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    //initiate a variable to count the score
    int score = 0;
    //do iteration through every single character inputted in the string
    for (int i = 0; word[i] != '\0'; i++)
    {
        //check whether the input is upper
        if (isupper(word[i]))
        {
            //add values to score by accesing the array
            //array index is determined by the words[i] - 'A'
            //since every index in POINTS is 65 away from 0, in this case A (65 at ASCII) away from 0
            //in case if word[i] = A, the index will be 0 since word[i] = 65, and A = 65
            score += POINTS[word[i] - 'A'];
        }
        //check whether the input is lower
        else if (islower(word[i]))
        {
            // add values to score by accesing the array
            // array index is determined by the words[i] - 'a'
            // since every index in POINTS is 97 away from 0, in this case a (97 at ASCII) away from 0
            // in case if word[i] = a, the index will be 0 since word[i] = 97, and A = 97
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}

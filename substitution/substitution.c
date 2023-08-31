#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string substitution(string text, string key);

//argc represent the argument in main, argv represent array of string for key
int main(int argc, string argv[])
{
    //count the length of the inputted key
    int n = strlen(argv[1]), repeated = 0;
    for (int i = 0; i < n; i++)
    {
        //check whether there is a symbol or number in the key, it is not prohibited!
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain letter only!\n");
            return 1;
        }

        //do a for loop inside the main loop to check whether there is a repeated letter
        //this loop start +1 from the outer loop since it will check whether our next letter is same with current letter
        for (int j = i + 1; j < n; j++)
        {
            //this validates whether our current character at index i is same as our checked character
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                //if there is a repeating character
                repeated++;
            }
        }
    }

    //if there is a repeating character, create an error note
    if (repeated != 0)
    {
        printf("There is a repeating character!\n");
        return 1;
    }

    //check if the inputted keywords contains 2 input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //check if the inputted key is 26 char
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //get plain text and print the converted ciphertext
    string text = get_string("plaintext: ");
    printf("ciphertext: %s\n", substitution(text, argv[1]));
}

string substitution(string text, string key)
{
    //go iterate through the plaintext
    for (int i = 0; text[i] != '\0'; i++)
    {
        //since we only cypher the letter, so we check whether our plaintext inputted is only consisted of letter
        if (isalpha(text[i]))
        {
            //this is the core substitution code
            //using the ternary operator (fancy method of implementing if-else)
            //this check if our current char is an uppercase, if it is, subtract our text with ASCII val of 'A', otherwise subtract it with val of 'a'
            int index = isupper(text[i]) ? text[i] - 'A' : text[i] - 'a';
            if (isupper(text[i]))
            {
                //this one check if our plain text is an uppercase, if it is, keep it that way
                text[i] = toupper(key[index]);
            }
            else
            {
                //otherwise we will keep it as lowercase
                text[i] = tolower(key[index]);
            }
        }
    }
    return text;
}
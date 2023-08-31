// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    //set counter for each parameter
    int upcase = 0;
    int lowcase = 0;
    int symb = 0;
    int num = 0;
    //iterate through the array of string input by user
    for (int i = 0; password[i] != '\0'; i++)
    {
        //checks whether in the inputted array consist of upper characters
        if (isupper(password[i]))
        {
            upcase++;
        }
        // checks whether in the inputted array consist of lower characters
        else if (islower(password[i]))
        {
            lowcase++;
        }
        // checks whether in the inputted array consist of symbol or punctuation
        else if (ispunct(password[i]))
        {
            symb++;
        }
        // checks whether in the inputted array consist of number or digit
        else if (isdigit(password[i]))
        {
            num++;
        }
    }

    //check each counter parameter counter
    //all counter must be higher than 0, meaning that they have each parameter conditions met
    if (upcase > 0 && lowcase > 0 && symb > 0 && num > 0)
    {
        return true;
    }
    return false;
}

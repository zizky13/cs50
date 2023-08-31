#include <cs50.h>
#include <stdio.h>

//as always introduction of the function
string replace(string inputString);

int main(int argc, string argv[])
{
    //check whethers the users input one string or not at all
    //if the user input no string or more than one string, immidiately pop error message with exit values of 1
    if (argc != 2)
    {
        printf("Missing line arguments!\n");
        return 1;
    }
    else
    {
        //if the condition met, print the values from the function
        printf("%s\n", replace(argv[1]));
    }
}

//never forget to change the parameter name so it doesn't conflict with the global var name
string replace(string inputString)
{
    //iterate through the string to find the vowels to be changed
    for (int i = 0; inputString[i] != '\0'; i++)
    {
        switch (inputString[i])
        {
            //reads if there is letter a in the words, if so, replace with 6
            case 'a':
                inputString[i] = '6';
                break;
            // reads if there is letter e in the words, if so, replace with 3
            case 'e':
                inputString[i] = '3';
                break;
            // reads if there is letter i in the words, if so, replace with 1
            case 'i':
                inputString[i] = '1';
                break;
            // reads if there is letter o in the words, if so, replace with 0
            case 'o':
                inputString[i] = '0';
                break;
            default:
                break;
        }
    }
    return inputString;
}

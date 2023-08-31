#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt (string plain, int key);

int main(int argc, string argv[])
{

    int length = strlen(argv[1]);
    int key;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for(int i = 0; i < length; i++)
    {
        if (!isdigit(argv[1][i]) || isblank(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    key = atoi(argv[1]);


    string plain = get_string("plaintext: ");
    printf("ciphertext: %s\n", encrypt(plain, key));
}



string encrypt (string plain, int key)
{
    for(int i = 0; plain[i] != '\0'; i++)
    {
        if (isupper(plain[i]))
        {
            plain[i] = (plain[i] + key - 'A') % 26 + 'A';
        }
        else
        {
            plain[i] = (plain[i] + key - 'a') % 26 + 'a';
        }
    }
    return plain;
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    int arr_length = sizeof(text) / sizeof(text[0]);

    string t = get_string("Text: ");
    for (int i = 0; i < arr_length; i++)
    {
        if (strcmp(text[i], t) == 0)
        {
            printf("Text found!\n");
            return 0;
        }
    }
    printf("Text not found!\n");
    return 1;
}
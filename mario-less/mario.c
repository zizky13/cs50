#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //this first 'for' will determine how many rows are there
    for (int i = 0; i < height; i++)
    {
        //since height will be our width, we will use this as parameter to print " " that will be printed until height - 1
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        //after printing " " for height-1, we then print # as much as i+1 (remember that at the first line, it only have 1 hash, second line we have 2 hashes and so on)
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
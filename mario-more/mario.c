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

    //this iteration determine how much rows we will have, the number of rows determined by the "height"
    for (int i = 0; i < height; i++)
    {
        //this one will print the spaces before the first "#"
        //the iteration will be determined by height-i-1
        //why? we want that each spaces will be shifted to left after each rows, thats why we add i to the iteration
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(".");
        }
        //after printing spaces as much as height - i - 1, we will then print "#"
        //this will be printed as much as i+1, remember that each rows has rows + 1 "#"
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //after printing the first left skewed pyramid, we add spaces in between
        printf("  ");
        //this iteration will print the right skewed pyramid, we dont need to pay attention to the spaces again
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }


        printf("\n");
    }
}
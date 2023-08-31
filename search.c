#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int number[] = {20, 500, 10, 5, 100, 1, 50};
    int arr_length = sizeof(number)/sizeof(number[0]);

    int n = get_int("Number: ");
    for (int i = 0; i < arr_length; i++)
    {
        if (number[i] == n)
        {
            printf("Number found!\n");
            return 0;
        }
    }
    printf("Number not found!\n");
    return 1;
}
#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    //checking whether number is less than 2 which equals to not a prime
    if (number < 2)
    {
        return false;
    }

    //doing iterations between 2 and number-1
    //if modulo of number divided by j is equal to 0, immidiately return false
    //else, return true which means that number is a prime number
    for (int j = 2; j <= number - 1; j++)
    {
        //this function will iterate until it meet the 'if' condition, or it will return number if the 'if' function is not met and iteration is over
        if (number % j == 0)
        {
            return false;
        }
    }
    return number;
}

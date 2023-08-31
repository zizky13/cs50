#include <cs50.h>
#include <math.h>
#include <stdio.h>

int n, m, years = 0;

int main(void)
{
    // TODO: Prompt for start size
    do
    {
        n = get_int("Starting size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size
    do
    {
        m = get_int("End size: ");
        if(n == m)
        {
            printf("Years: 0\n");
            return 0;
        }
    }
    while (m <= n);

    // TODO: Calculate number of years until we reach threshold
    do
    {
        n = n + floor((n / 3)) - floor((n / 4));
        years++;
    }
    while (n < m);
    // TODO: Print number of years

    printf("Years: %i\n", years);
}

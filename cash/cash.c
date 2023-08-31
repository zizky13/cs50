#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    return cents;
}

int calculate_quarters(int cents)
{
    //initialize the counter for quarter
    int quarters = 0;
    //create iteration with cents as ending parameter
    for (int i = 1; i <= cents; i++)
    {
        //check whether the current cents value is divisible by 25
        //if it is divisible by 25, it is a quarters, and we can add quarters counter
        if (i % 25 == 0)
        {
            quarters++;
        }

    }
    return quarters;
}

int calculate_dimes(int cents)
{
    //same concept with quarters
    int dimes = 0;
    for (int i = 1; i <= cents; i++)
    {
        if (i % 10 == 0)
        {
            dimes++;
        }
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // same concept with quarters
    int nickels = 0;
    for (int i = 1; i <= cents; i++)
    {
        if (i % 5 == 0)
        {
            nickels++;
        }
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // same concept with quarters
    int pennies = 0;
    for (int i = 1; i <= cents; i++)
    {
        if (i % 1 == 0)
        {
            pennies++;
        }
    }
    return pennies;
}

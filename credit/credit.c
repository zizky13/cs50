#include <cs50.h>
#include <stdio.h>

long get_card_number(void);
int checksum(long card_number);
void final_check(int checksum, long card_number);

int main(void)
{
    long card_num = get_card_number();
    int card_sum = checksum(card_num);
    final_check(card_sum, card_num);

    return 0;
}

long get_card_number(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    } while (number <= 0);

    return number;
}

int checksum(long card_number)
{
    long initial_cardnum = card_number;
    long sum = 0;
    long sum_doubled = 0;
    long last_digit = 0;

    while (initial_cardnum > 0)
    {
        last_digit = initial_cardnum % 10;
        sum = sum + last_digit;
        initial_cardnum = initial_cardnum / 100;
    }

    initial_cardnum = card_number / 10;
    last_digit = 0;

    while (initial_cardnum > 0)
    {
        last_digit = (initial_cardnum % 10)*2;
        sum_doubled = sum_doubled + (last_digit % 10) + (last_digit / 10);
        initial_cardnum = initial_cardnum / 100;
    }

    long total = sum + sum_doubled;

    if (total % 10 == 0)
    {
        return 1;
    }

    return 0;
}

void final_check(int checksum, long card_number)
{
    long valid_cc = card_number;
    int length = 0;
    long divisor = 10;
    int first_digit;
    int firsttwo_digit;

    if (checksum == 1)
    {
        while (valid_cc > 0)
        {
            valid_cc /= 10;
            length++;
        }

        valid_cc = card_number;
        for (int i = 0; i < (length - 2); i++)
        {
            divisor *= 10;
        }

        first_digit = valid_cc / divisor;
        firsttwo_digit = valid_cc / (divisor / 10);

        if (length == 15 && (firsttwo_digit == 34 || firsttwo_digit == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (firsttwo_digit == 51 || firsttwo_digit == 52 || firsttwo_digit == 53 || firsttwo_digit == 54 || firsttwo_digit == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && (first_digit == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

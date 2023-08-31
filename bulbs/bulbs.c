#include <cs50.h>
#include <stdio.h>
#include <string.h>

// bits in byte indicates how much space in a byte array
// int count is used to count the length of the inputted text
// binary is the array used to store the converted decimals to binary, and it is initiated to {0, 0, 0, 0, 0, 0, 0, 0}
const int BITS_IN_BYTE = 8;
int count = 0, binary[] = {0, 0, 0, 0, 0, 0, 0, 0};

//prototyping the function
void print_bulb(int bit);

int main(void)
{
    //take the string from user
    //making count of how length is the inputted string
    string text = get_string("Message: ");
    count = strlen(text);

    //initiate the decimal array to store converted text values to ascii code
    //the length of the array should be equal to the length of the text
    int decimal[count];

    //iterate through the decimal array
    //store every ascii value of the arr text to arr decimal
    for (int i = 0; i < count; i++)
    {
        decimal[i] = text[i];
    }

    //iniate a counter for the inside iteration
    int j = 0;

    //iterate through the decimal in inverted order
    for (int i = count - 1; i >= 0; i--)
    {
        //initiate the temporary variable as we want to preserve the original decimal[i] value
        int num = decimal[i];

        //iterate through the binary index array
        //the binary using j as index to avoid value overwritten since every iteration of i will start the k at 0 again
        //thats why we use j as seperate index to add it value more and more and avoid overwrite over existing binary value
        for (int k = 0; k < BITS_IN_BYTE; k++)
        {
            //fills the binary number as modulo of num and 2
            //divide num every iteration
            //add j value every iteration
            binary[j] = num % 2;
            num /= 2;
            j++;
        }
    }

    //create a check counter
    int check = 0;

    //initiate an iteration from the last index of binary array to 0
    //the reverse is initiated since we store our binary from left to right, meanwhile binary is being red from right to left
    for (int i = BITS_IN_BYTE * count - 1; i >= 0; i--)
    {
        //calls the function every iteration, and put the binary[i] number as parameter
        //add 1 to check every iteration
        print_bulb(binary[i]);
        check++;

        //if the check is equal to 8, that means we already printed 8 bulbs
        if (check == 8)
        {
            //for every 8 bulbs, we create new line
            //and then we reinitiate the check to 0 again for another iteration
            puts("");
            check = 0;
        }
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main (void)
{
    person people[2];
    people[0].name = "Connor";
    people[0].number = "0878-1466-7991";
    people[1].name = "David";
    people[1].number = "0878-7991-044";
    int length = sizeof(people)/sizeof(people[0]);

    string n = get_string("Name: ");
    for (int i = 0; i < length; i++)
    {
        if(strcmp(people[i].name, n) == 0)
        {
            printf("The number is: %s\n", people[i].number);
            return 0;
        }
    }
    printf("Number not found!\n");
    return 1;
}
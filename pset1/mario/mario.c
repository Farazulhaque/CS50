#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int i;
    int j;
    int k;

    do
    {
        //get no of rows as input
        height = get_int("Height: ");
    }
    //check for the valid input i.e in between 1-8
    while (height < 1 || height > 8);

    //loop through through the number of height
    for (i = height; i >= 1; i--)
    {
        //check for the condition i.e no of spaces is less than i.
        for (j = 1; j < i; j++)
        {
            printf(" ");
        }

        //check for the condition i.e no. of hashes is greter than or equal to i.
        for (k = height; k >= i; k--)
        {
            printf("#");
        }

        printf("  ");

        for (k = height; k >= i; k--)
        {
            printf("#");
        }


        printf("\n");
    }

}
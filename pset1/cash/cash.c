#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    float amount = 0;
    int cents = 0;
    int count = 0;
    int amount_left = 0;
    do
    {
        amount = get_float("Change owed: ");
    }
    while (amount < 0);                 //To get only positive value

    cents = (int)round(amount * 100);   //convert dollar in cents i.e 1 dollar = 100 cents. 23dollar = 2300cents. 0.25dollar = 25cents

    amount_left = cents;                //store total no of cents in a variable

    count += amount_left / 25;          //first divide amount_left by 25 (we get quotient on using / operator) and add it to count
                                        //and then update the count variable
    amount_left %= 25;                  //divide amount_left by 25 (we get remainder on using % operator) and update the value of amount_left

    count += amount_left / 10;          //Similarly, do all the below step for 10cents,5cents
    amount_left %= 10;

    count += amount_left / 5;
    amount_left %= 5;

    count += amount_left;               //Since, amount_left / 1 is equal to amount_left

    printf("%d\n", count);              //Finally print the total no of cents count
}
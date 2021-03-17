#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_population;
    do
    {
        start_population = get_int("Start size: ");
    }
    while (start_population < 9);

    // TODO: Prompt for end size
    int end_population;
    do
    {
        end_population = get_int("End size: ");
    }
    while (end_population < start_population);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int new_pop = start_population;
    for (int old_pop = start_population;
         new_pop < end_population;
         years++)
    {
        new_pop = new_pop + old_pop / 3 - old_pop / 4;
        old_pop = new_pop;
    }

    // TODO: Print number of years
    printf("Years: %d\n", years);
}
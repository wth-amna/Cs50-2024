#include <cs50.h>
#include <stdio.h>

void print_bricks(int bricks);
void print_space(int iteration, int height);
int main(void)
{
    // Prompt the user for the pyramid's height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Print a pyramid of that height
    for (int i = 0; i < height; i++)
    {

        // print space to make pyramid on right side
        print_space(i, height);
        // print bricks
        print_bricks(i);
    }
}


// This function prints spaces in a line.
// The number of spaces printed depends on the current iteration and the total height.
void print_space(int iteration, int height)
{
    for (int k = iteration + 1; k < height; k++)
    {
        printf(" ");
    }
}

// This function prints a number of bricks represented by '#'.
void print_bricks(int bricks)
{
    for (int j = 0; j < bricks + 1 ; j++)
    {
        printf("#");
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int actualNum = rand() % 100;
    int guess = -1;
    int attempts = 0;

    printf("**********Welcome to the Guess the Number game!***********\n");
    printf("I am thinking of a number between 0 and 100\n");

    while (1)
    {
        attempts++;
        printf("\nEnter your guess: ");
        scanf("\n");
        scanf(" %d", &guess);

        if (guess == actualNum)
        {
            printf("Yeahhhh..... You guessed it right in %d attempts \n", attempts);
            break;
        }

        if (guess > actualNum)
        {
            printf("Too high.... Try again\n");
        }
        else
        {
            printf("Too low... Try again\n");
        }
    }

    return 0;
}

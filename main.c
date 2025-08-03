#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Functions Prototypes
int getRandomNumber(int max, int min);
int leaveOrTryAgain();

int main()
{
    // random number to guess
    int min = 0;
    int max = 100;

    // let the set the range
    printf("Enter the minimum number: ");
    scanf("%d", &min);
    printf("Enter the maximum number: ");
    scanf("%d", &max);

    int correctGuess = getRandomNumber(max, min);

    // user input: the guess
    int guess = 0;

    // process the guess
    while (correctGuess != guess)
    {

        // read user input
        printf("Enter Your Guess between %d and %d: ", min, max);
        scanf("%d", &guess);

        if (correctGuess == guess)
        {
            printf("Congratulations, your guess was correct!\n\n");
        }
        else if (guess - 1 == correctGuess || guess + 1 == correctGuess)
        {
            printf("You are very NEAR to the correct answer!\n\n");
        }
        else if (guess > correctGuess)
        {
            printf("Too HIGH!\n\n");
        }
        else if (guess < correctGuess)
        {
            printf("Too LOW!\n\n");
        }
    }

    // user decision to leave the game or play again
    int userLeaveOrPlay = leaveOrTryAgain();
    if (userLeaveOrPlay == 1)
    {
        main();
    }
    else
    {
        printf("See you later! Goodbye.\n");
    }

    return 0;
}

// Functions
int getRandomNumber(int max, int min)
{
    srand(time(0));
    int correctNumber = (rand() % (max - min + 1)) + min;
    return correctNumber;
}

int leaveOrTryAgain()
{
    char choice = '\0';
    printf("Thank you for playing, would you like to leave or play again (Y for Yes or N for No)? ");
    scanf(" %c", &choice);
    return choice == 'Y' || choice == 'y' ? 1 : 0;
}
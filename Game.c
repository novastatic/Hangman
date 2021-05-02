#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "FileReading.h"

void runGame()
{
    char guesses[28];
    char guessedLetter;
    int counter = 0;

    do
    {
        userInput(&guessedLetter, guesses, counter);
        guesses[counter] = guessedLetter;
        counter++;
    }
    while(counter < 3);
}

void userInput(char* input, char guessArray[], int counter)
{
    int check;

    do
    {
        check = 0;

        printf("Please input your guess: ");
        scanf("%c", input);
        fflush(stdin);

        if(isLetter(*input) == 0)
        {
            printf("%i", isLetter(*input));
            printf("Your guess is not a letter\n");
        }
        for(int i = 0; i < counter; i++)
            if(guessArray[i] == *input)
            {
                printf("You have already guessed this letter!");
                check--;
            }
        check++;
    }
    while(check == 0);
}

int isLetter(char* letter)
{
    if(isalpha(letter) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "FileReading.h"

void runGame()
{
    char guesses[28];
    char* solution = malloc(42);
    char guessedLetter;
    int counter = 0;

    generateWord(solution);

    //setCursor(4, 5);
    //printf("You have already guessed these letters: ");
    printf("%s", solution);

    do
    {
        userInput(&guessedLetter, guesses, counter);
        guesses[counter] = tolower(guessedLetter);
        counter++;
        quickSortGuessArray(guesses, 0, counter - 1);
        checkGuess(solution, guesses, guessedLetter);
    }
    while(counter < 10);
    printf("%i", counter);
    puts(guesses);


    printf("\n%s\n", guesses);

}

void userInput(char* input, char guessArray[], int counter)
{
    int check;
    //setCursor(4, 7);

    do
    {
        check = 1;
        printf("Please input your guess: ");
        scanf("%c", input);
        fflush(stdin);

        if(isLetter(*input) == 0)
        {
            printf("%i", isLetter(*input));
            printf("Your guess is not a letter\n");
            check = 0;
        }
        else
        {
            for(int i = 0; i < counter; i++)
            {
                if(guessArray[i] == *input)
                {
                    printf("You have already guessed this letter!");
                    check = 0;
                }
            }
        }
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
void quickSortGuessArray(char guesses[], int left, int right)
{
    int i, j, pivot, temp;

    if (left < right)
    {
        pivot = left;
        i = left;
        j = right;

        while(i < j)
        {
            while(guesses[i] <= guesses[pivot] && i < right)
            {
                i++;
            }
            while(guesses[j] > guesses[pivot])
            {
                j--;
            }
            if(i < j)
            {
                temp = guesses[i];
                guesses[i] = guesses[j];
                guesses[j] = temp;
            }
        }
        temp = guesses[pivot];
        guesses[pivot] = guesses[j];
        guesses[j] = temp;

        quickSortGuessArray(guesses, left, j - 1);
        quickSortGuessArray(guesses, j + 1, right);
    }
}

int checkGuess(char solution[], char guesses[], char guessedLetter)
{
    int correctGuess, lastGuessCorrect = 0;
    printf("%i, %i\n", strlen(guesses), strlen(solution));

    for(int i = 0; i < strlen(solution) - 1; i++)
    {
        correctGuess = 0;
        for(int j = 0; j < strlen(guesses); j++)
        {
            if(tolower(solution[i]) == tolower(guesses[j]))
            {
                correctGuess = 1;
                if(i == 0)
                {
                    printf("%c",toupper(guesses[j]));
                }
                else
                {
                    printf("%c", tolower(guesses[j]));
                }
            }
            if(tolower(guessedLetter) == tolower(solution[i]))
            {
                lastGuessCorrect = 1;
            }
        }
        if(!correctGuess)
        {
            printf("_ ");
        }
    }
    if(lastGuessCorrect)
    {
        printf("Your guess was correct!");
    }
    else
    {
        printf("Wrong guess sucker!");
    }

    if(correctGuess)
    {
        return 0
    }
    else
    {
        return 1;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "FileReading.h"
#include "Interface.h"

int checkGuessSuccess(char solution[], char guesses[], char guessedLetter);

void runGame()
{
    char guesses[28];
    char* solution = malloc(42);
    char guessedLetter;
    int counter = 0, correctGuesses = 0, lastGuessResult, gameState;

    generateWord(solution);


    printf("%s", solution);

    do
    {
        userInput(&guessedLetter, guesses, counter);
        guesses[counter] = tolower(guessedLetter);
        counter++;
        quickSortGuessArray(guesses, 0, counter - 1);
        lastGuessResult = checkGuessSuccess(solution, guesses, guessedLetter);
        if(lastGuessResult == 1)
        {
            correctGuesses++;
        }
        gameState = checkGameState(lastGuessResult, correctGuesses, counter);
    }
    while(!gameState);

    if(gameState == 1)
    {
        printf("Game lost");
    }
    else if(gameState == 2)
    {
        printf("Game won");
    }
}

void userInput(char* input, char guessArray[], int counter)
{
    int check;
    setCursor(4, 19);

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

int checkGuessSuccess(char solution[], char guesses[], char guessedLetter)
{
    int correctGuess, lastGuessCorrect = 0, wordComplete = 1;

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
                    setCursor(4+j, 18);
                    printf("%c",toupper(guesses[j]));
                }
                else
                {
                    setCursor(4+j, 18);
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
            setCursor(22, 14);
            printf("_");
            wordComplete = 0;
        }
    }
    if(lastGuessCorrect)
    {
        setCursor(22, 12);
        printf("                     ");
        setCursor(22, 12);
        printf("Your guess was correct!");
        if(wordComplete)
        {
            return 2;
        }
        return 1;
    }
    else
    {
        setCursor(12, 12);
        printf("                     ");
        setCursor(12, 12);
        printf("Wrong guess sucker!");
        return 0;
    }

}
int checkGameState(int lastGuessSuccess, int correctGuesses, int guessCounter)
{
    int wrongGuesses = guessCounter - correctGuesses;

    switch(lastGuessSuccess)
    {
        case 0:
            //drawHangman(wrongGuesses);
            if(wrongGuesses < 7)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        case 1:
            correctGuesses++;
            return 0;
        case 2:
            return 2;

    }
}

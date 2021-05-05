#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "FileReading.h"

static int partition(char guesses[], int left, int right);

void runGame()
{
    char guesses[28];
    char* solution = malloc(42);
    char guessedLetter;
    int counter = 0;

    generateWord(solution);
    printf("%s", solution);

    //setCursor(4, 5);
    //printf("You have already guessed these letters: ");

    do
    {
        userInput(&guessedLetter, guesses, counter);
        guesses[counter] = tolower(guessedLetter);
        counter++;
        checkGuess(solution, guesses);

    }

    while(counter < 5);

    quickSortGuessArray(guesses, 0, counter - 1);

    for(int i = 0; i < counter; i++)
    {
        //setCursor(44 + i, 5);
        printf("%c", guesses[i]);
    }
}

void userInput(char* input, char guessArray[], int counter)
{
    int check;
    //setCursor(4, 7);

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
extern void quickSortGuessArray(char guesses[], int left, int right)
{
    int i;

    if (left < right)
    {
        i = partition(guesses, left, right);
        quickSortGuessArray(guesses, left, i - 1);
        quickSortGuessArray(guesses, i + 1, right);
    }
}
static int partition(char guesses[], int left, int right)
{
    int pivot, i, j, temp;
    pivot = guesses[left];
    i = left;
    j = right + 1;

    while(1)
    {
        do i++;
        while(guesses[i] <= pivot && i <= right);

        do j--;
        while(guesses[j] > pivot);

        if(i >= j) break;

        temp = guesses[i];
        guesses[i] = guesses[j];
        guesses[j] = temp;
    }
    temp = guesses[left];
    guesses[left] = guesses[right];
    guesses[j] = temp;
    return j;
}

void checkGuess(char solution[], char guesses[])
{
    int correctGuess;
    printf("%i", strlen(guesses));
    printf("%i", strlen(solution));
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
        }
        if(!correctGuess)
        {
            printf("_");
        }
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "FileReading.h"
#include "Interface.h"

int checkGuessSuccess(char solution[], char guesses[], char guessedLetter);

/**
 *  This is the function for the main game loop,
 *  all other functions come together here to run
 *  the game.
 **/
void runGame()
{
    //variable declaration
    char guesses[28];
    char* solution = malloc(42);
    char guessedLetter;
    int counter = 0, correctGuesses = 0, lastGuessResult, gameState = 0;

    //generating the guess word
    generateWord(solution);

<<<<<<< HEAD
    //loop for reading input then checking with the guess word and progressing the
    //game accordingly
    do
    {
        //getting user input
=======
    double gameDuration(gameState);

    printf("%s", solution);

    do
    {
        double gameDuration(gameState);
>>>>>>> d67a024abb0d39e032cc492873235af66cde33a3
        userInput(&guessedLetter, guesses, counter);
        //saving the given guess of the user to an array of the guesses
        guesses[counter] = tolower(guessedLetter);
        counter++;
        //sorting the guess array in alphabetical order via quicksort
        quickSortGuessArray(guesses, 0, counter - 1);
        //printing the given guesses
        printGivenGuesses(guesses);
        //getting the result of the last guess
        lastGuessResult = checkGuessSuccess(solution, guesses, guessedLetter);
        //checking if the last guess was correct
        if(lastGuessResult == 1)
        {
            correctGuesses++;
        }
        //getting the game state so the game knows how to go on
        gameState = checkGameState(lastGuessResult, correctGuesses, counter);
    }
    //loop is running as long as the game is neither lost nor won
    while(!gameState);

    //checking if the game was lost or won
    if(gameState == 1)
    {
        setCursor(25, 25);
        printf("Game lost");
    }
    else if(gameState == 2)
    {
        setCursor(25, 25);
        printf("Game won!");
    }
}
/**
 *  This function gets the user input and saves
 *  it into an char pointer, it also needs the given guesses
 *  and amount of guesses to check for validity of the input
 *
 *  @param char* input, char guessArray[], int counter
 **/
void userInput(char* input, char guessArray[], int counter)
{
    //variable declaration
    int check;
    //cursor positioning
    setCursor(4, 19);

    //do while loop to get repeated input if input is invalid
    do
    {
        //getting user input
        check = 1;
        printf("Please input your guess: ");
        scanf("%c", input);
        fflush(stdin);

        //checking if the user input is a letter
        if(isLetter(*input) == 0)
        {
            printf("%i", isLetter(*input));
            printf("Your guess is not a letter\n");
            check = 0;
        }
        //checking if the user already guessed this letter
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
    //run as long as there is no valid input
    while(check == 0);
}

/**
 *  This function checks if a given character
 *  is a letter
 *
 *  @param char* letter
 *  return 1 if input is a letter else 0
 **/
int isLetter(char* letter)
{
    //checking if the input is a letter using isalpha method
    if(isalpha(letter) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**
 *  This function sorts an given array using the quicksort
 *  algorithm
 *
 *  @param char guesses[], int left, int right
 **/
void quickSortGuessArray(char guesses[], int left, int right)
{
    //variable declaration
    int i, j, pivot, temp;

    //checking if left starting point is smaller than the one on the right
    if (left < right)
    {
        pivot = left;
        i = left;
        j = right;


        while(i < j)
        {
            //finding a pair of entries to switch
            while(guesses[i] <= guesses[pivot] && i < right)
            {
                i++;
            }
            while(guesses[j] > guesses[pivot])
            {
                j--;
            }
            //when pair is found switch them
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

        //recursive function calling to get whole array sorted
        quickSortGuessArray(guesses, left, j - 1);
        quickSortGuessArray(guesses, j + 1, right);
    }
}
/**
 *  This function checks if the last guess was a success
 *
 *  @param char solution[], char guesses[], char guessedLetter
 *  return 0 on wrong guess, 1 on right guess and 2 when word is completly guesses
 **/
int checkGuessSuccess(char solution[], char guesses[], char guessedLetter)
{
    //variable declaration
    int correctGuess, lastGuessCorrect = 0, wordComplete = 1;

    //comparing solution with the given guesses
    for(int i = 0; i < strlen(solution) - 1; i++)
    {
        correctGuess = 0;
        for(int j = 0; j < strlen(guesses); j++)
        {
            //when a match is found print the letter
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
        setCursor(42, 12);
        printf("                             ");
        setCursor(42, 12);
        printf("Your guess was correct!");
        if(wordComplete)
        {
            return 2;
        }
        return 1;
    }
    else
    {
        setCursor(42, 12);
        printf("                           ");
        setCursor(42, 12);
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
            drawHangman(wrongGuesses);
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
void printGivenGuesses(char guesses[])
{
    printf("You guessed letters until now: ");
    for(int i = 0; i < strlen(guesses); i++)
    {
        if(i == strlen(guesses) - 1)
        {
            printf("%c", guesses[i]);
        }
        else
        {
            printf("%c, ", guesses[i]);
        }
    }
    printf("\n");
}

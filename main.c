/**
* Title: Hangman
* Author: Maximilian Hedderich & Antonia Lenz
* Created: 05.05.2021
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <dos.h>

// Function prototypes
void userInput();
void runGame();
void sound();
int gameModeSelect();
void drawFrame(int frameWidth, int frameHeight);
void drawHeader();
void drawHangman();
int checkGivenGuesses(char input);
int setCursor(int x, int y);


int main()
{
    // Draw frame around game
    drawFrame(75, 120);

    setCursor(17, 3);
    drawHeader();

    setCursor(4, 16);
    //inputNames();
    //gameModeSelect();
    //setCursor(60, 1);
    //countdown(60, 1);

    setCursor(4, 23);
    runGame();

    // Outro sound
    sound();


    // End/Errorsound
    printf("\a");

    return 0;
}


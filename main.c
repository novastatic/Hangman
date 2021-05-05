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


void userInput();
void runGame();
void sound();
void drawFrame(int frameWidth, int frameHeight);
int checkGivenGuesses(char input);
int setCursor(int x, int y);
int setColor(char color);



int main()
{
    // Draw frame around game
    drawFrame(65, 30);

    // Intro sound
    //sound();

    setCursor(17, 3);
    printf("\xb0\xb1\xb2 Welcome to Hangman \xb2\xb1\xb0\n");
    setCursor(4, 6);
    runGame();

    // End/Errorsound
    printf("\a");

    return 0;
}


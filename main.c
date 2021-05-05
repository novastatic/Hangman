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
int gameModeSelect();
void drawFrame(int frameWidth, int frameHeight);
void drawHeader();
int drawHangman();
int checkGivenGuesses(char input);
int setCursor(int x, int y);
//int setColor(char color);



int main()
{
    // Draw frame around game
    drawFrame(75, 20);

    setCursor(17, 3);
    drawHeader();

    setCursor(4, 6);
    //gameModeSelect();
    //setCursor(60, 1);
    //countdown(60, 1);

    setCursor(4, 6);
    runGame();

    setCursor(27, 11);
    drawHangman(7);

    // Outro sound
    sound();


    // End/Errorsound
    printf("\a");

    return 0;
}


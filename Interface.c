/**
* Title: Hangman/Interface
* Description: This file contains all functions concerning user interface and sound
* Author: Maximilian Hedderich & Antonia Lenz
* Created: 05.05.2021
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include "Interface.h"


/**
 *  This function sets the cursor on the console application depending on the expected X/Y-coordinates on the screen.
 *  It is used to make the application look more appealing and control the position of each element on the screen.
 *
 *  @param int x, int y
 *  return int
 **/
int setCursor(int x, int y)
{
    COORD coordinates;
    coordinates.X= x;
    coordinates.Y= y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
    return 0;
}


/**
 *  This function draws a frame for the game.
 *  It expects values for width and height.
 *
 *  @param const int x, const int y
 *  return int
 **/
 void drawFrame(const int frameWidth, const int frameHeight)
 {
    int i,j;

    // Output a frame
    for (i = 0; i < frameHeight; i++)
    {
        for (j = 0; j < frameWidth; j++)
        {
            if (i == 0 && j == 0)
                printf("\xC9");
            else if (i == 0 && j == frameWidth-1)
                printf("\xBB");
            else if (i == frameHeight-1 && j == 0)
                printf("\xC8");
            else if (i == frameHeight-1 && j == frameWidth-1)
                printf("\xBC");
            else if (i == 0 || i == frameHeight-1)
                printf("\xCD");
            else if (j == 0 || j == frameWidth-1)
                printf("\xBA");
            else
                printf(" ");
        }
        printf("\n");
    }

 }

int gameModeSelect()
{
    int modeSelection = 0;

    printf("\bChose your game mode: \n");
    printf("1. Timelord (Type 1 to play against the 60 second timer) \n");
    printf("2. Companion (Type 2 to play with a friend) \n");
    printf("3. Mastermode (Type 3 to play with a friend against the timer)");
    printf("\n\bYour choice: ");
    scanf("%d", modeSelection);

    return modeSelection;

}

 int countdown(int timeLeft, int winGame)
 {
    while(timeLeft != 0 && winGame == 1)
    {
        setCursor(60, 1);
        printf("Timer: %d", timeLeft);
        timeLeft--;
        Sleep(1);
    }
    return timeLeft;
 }

 void drawHeader() {
    setCursor(17, 3);
    printf("\xb0\xb1\xb2 _  _ ____ _  _ ____ _  _ ____ _  _ \xb2\xb1\xb0\n");
    setCursor(17, 4);
    printf("\xb0\xb1\xb2 |__| |__| |\\ | | __ |\\/| |__| |\\ | \xb2\xb1\xb0\n");
    setCursor(17, 5);
    printf("\xb0\xb1\xb2 |  | |  | | \\| |__] |  | |  | | \\| \xb2\xb1\xb0\n");
    setCursor(17, 6);
    printf("\xb0\xb1\xb2 ^  ^ ^  ^ ^  ^ ^  ^ ^  ^ ^  ^ ^  ^ \xb2\xb1\xb0\n");
 }

 int setColor(char color)
{
    /*
    Farbattribute werden durch ZWEI hexadezimale Ziffern angegeben - die erste
    bezieht sich auf den Hintergrund, die zweite auf den Vordergrund. Jede Ziffer
    kann einen der folgenden Werte annehmen:

    0 = Schwarz        8 = Dunkelgrau
    1 = Dunkelblau     9 = Blau
    2 = Dunkelgrün     A = Grün
    3 = Blaugrün       B = Zyan
    4 = Dunkelrot      C = Rot
    5 = Lila           D = Magenta
    6 = Ocker          E = Gelb
    7 = Hellgrau       F = Weiß

    Wenn der COLOR-Befehl ohne Argument aufgerufen wird, werden die Farbein-
    stellungen wiederhergestellt, mit denen CMD.EXE gestartet wurde. Diese werden
    durch das aktuelle Konsolenfenster, die /T-Befehlszeilenoption oder durch den
    Registrierungswert "DefaultColor" bestimmt.
    */
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );

    SetConsoleTextAttribute( hstdout, color );

    return 0;
}

 int drawHangman(int wrongGuess)
 {
    switch(wrongGuess)
    {
        case 0: printf(" ");
        case 1: printf("  +----+  \n");
        case 2: setCursor(27, 14);
                printf("  +----+  \n");
                printf("  |    |  \n");
        case 3: setCursor(27, 15);
                printf("  +----+  \n");
                printf("  |    |  \n");
                printf("  O    |  \n");
        case 4: setCursor(27, 16);
                printf("  +----+  \n");
                printf("  |    |  \n");
                printf("  O    |  \n");
                printf(" /|\\   |  \n");
        case 5: setCursor(27, 17);
                printf("  +----+  \n");
                printf("  |    |  \n");
                printf("  O    |  \n");
                printf(" /|\\   |  \n");
                printf(" / \\   |  \n");
        case 6: setCursor(27, 18);
                printf("  +----+  \n");
                printf("  |    |  \n");
                printf("  O    |  \n");
                printf(" /|\\   |  \n");
                printf(" / \\   |  \n");
                printf("     / |  \n");
        case 7: setCursor(27, 19);
                printf("  +----+  \n");
                printf("  |    |  \n");
                printf("  x    |  \n");
                printf(" /|\\   |  \n");
                printf(" / \\   |  \n");
                printf("     / |  \n");
                printf("=========\n");
                setCursor(20, 20);
                //setColor('4');
                printf("YOU KILLED THE HANGMAN! \n");
                //setColor('F');
                return 0;
    }
 }

/**
 *  This function plays the startup sound. The frequencies and durations to be played are part of the function.
 *  It starts playing when the game starts. The melody is "The hanging tree".
 *
 *  @param none
 *  return void
 **/
void sound()
{
// Array for frequencies (startup sound: "The hanging tree")

    int notes[53] =
    {
        0, NOTE_G4,
        NOTE_A4, 0, NOTE_C5,
        NOTE_D5, 0,
        NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4,
        NOTE_E4, 0, NOTE_G4,
        NOTE_A4, NOTE_A4, NOTE_C5,
        NOTE_D5, 0, NOTE_G4,
        NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4,
        NOTE_A4, 0,
        NOTE_E5, NOTE_D5, NOTE_C5,
        NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4,
        NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4,
        NOTE_E4, 0, NOTE_G4,
        NOTE_A4, 0, NOTE_C5,
        NOTE_D5, 0, NOTE_G4,
        NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4,
        NOTE_A4, 0

    };

// Array for durations (1000/4 = 250 = quarter note, 1000/8 = 125 = eighth note etc. )

    int durations[53] =
    {
        750, 250,
        250, 500, 250,
        250, 750,
        250, 250, 250, 250,
        250, 500, 250,
        500, 250, 250,
        250, 500, 250,
        250, 250, 250, 250,
        250, 750,
        500, 250, 250,
        250, 250, 250, 250,
        250, 250, 250, 250,
        250, 500, 250,
        250, 500, 250,
        500, 250, 250,
        250, 250, 250,250,
        750, 250

    };

// Iterate through notes and frequencies to run Beep() with the correct values and play the song
    for(int i = 0; i < 53; i++)
    {
        Beep(notes[i], durations[i]);
    }
}

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
 *  @param int x, int y
 *  return int
 **/
 void drawFrame(int frameWidth, int frameHeight)
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

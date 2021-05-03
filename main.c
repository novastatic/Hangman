#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <dos.h>


void userInput();
void sound();
int checkGivenGuesses(char input);
int setCursor(int x, int y);
int setColor(char color);



int main()
{
    const int frameWidth = 65, frameHeight = 30;
    int i, j;

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
    // Intro sound
    sound();
    setCursor(17, 3);
    printf("\xb0\xb1\xb2 Welcome to Hangman \xb2\xb1\xb0\n");
    setCursor(4, 6);
    runGame();

    // End/Errorsound
    printf("\a");

    return 0;
}

int setCursor(int x, int y)
{
    COORD coordinates;
    coordinates.X= x;
    coordinates.Y= y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
    return 0;
}

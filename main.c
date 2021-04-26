#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>


void userInput();
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
    setCursor(17, 3);
    printf("\xb0\xb1\xb2 Welcome to Hangman \xb2\xb1\xb0\n");
    setCursor(4, 6);
    userInput();

    return 0;
}

void userInput()
{
    char input;
    int check;

    do
    {
        printf("Please input your guess: ");
        scanf("%c", &input);

        if(checkGivenGuesses(input) == 0)
        {
            printf("You already guessed this letter!");
        }
        else
        {
            check++;
        }
        fflush(stdin);
    }
    while(check == 0);
}

int checkGivenGuesses(char input)
{
    char alphabet[28] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'ä', 'ü', 'ö'};

    input = tolower(input);
    for(int i = 0; i < strlen(alphabet); i++)
    {
        if(input == alphabet[i])
        {
            alphabet[i] = toupper(alphabet[i]);
            return 1;
        }
    }
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

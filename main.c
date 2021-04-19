#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void userInput();
int checkGivenGuesses(char input);

int main()
{
    printf("Welcome to Hangman\n");
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

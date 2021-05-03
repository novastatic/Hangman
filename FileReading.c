#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void generateWord(char *guessWord[])
{
    FILE *inputFile;

    srand(time(NULL));
    int line = rand() % 10;

    inputFile = fopen("Wordlist.txt", "r");

    if(!inputFile)
    {
        return "";
    }
    else
    {
        fgets(guessWord, 42, inputFile);
    }
}



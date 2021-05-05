#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void gameLoop();
void userInput(char *pointer[]);
int isLetter(char letter);
extern void quickSortGuessArray(char guesses[], int left, int right);
void checkGuess(char solution[], char guesses[]);

#endif // GAME_H_INCLUDED

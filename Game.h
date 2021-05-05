#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void gameLoop();
void userInput(char *pointer[]);
int isLetter(char letter);
void quickSortGuessArray(char guesses[], int left, int right);
int checkGuessSuccess(char solution[], char guesses[], char guessedLetter);
int checkGameState(int lastGuessSuccess, int *correctGuesses, int guessCounter);

#endif // GAME_H_INCLUDED

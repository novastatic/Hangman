#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void runGame();
void userInput(char* input, char guessArray[], int counter);
int isLetter(char letter);
void quickSortGuessArray(char guesses[], int left, int right);
int checkGameState(int lastGuessSuccess, int correctGuesses, int guessCounter);
int checkGuessSuccess(char solution[], char guesses[], char guessedLetter);
void printGivenGuesses(char guesses[], int guessCounter, int correctGuesses);


#endif // GAME_H_INCLUDED

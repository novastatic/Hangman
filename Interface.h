#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

// Define frequencies of notes to be played for sound()
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

// Function prototypes for Interface.c
void sound();
int setCursor(int x, int y);
int setColor(char color);
void drawFrame(int frameWidth, int frameHeight);
void drawHangman(int wrongGuess);
void drawHeader();
void countDown(int timeLeft, int winGame);
int gameModeSelect();
double gameDuration(int endGame);



#endif // INTERFACE_H_INCLUDED

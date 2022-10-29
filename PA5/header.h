#define _CRT_SECURE_NO_WARNINGS
#define clrscr() printf("\e[1;1H\e[2J")
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>


int userMenu();
void initScoreboard(int scoreboard[][14]);
void printRules();
int roll(int rolls, int kept, int die[]);
void printDie(int die[], int kept);
void keepDie(int die[], int index, int count);
void playerRoll(int player, int die[], int scoreboard[][14]);
void playerScore(int player, int die[], int scoreboard[][14]);
void convArray(int die[], int converted[]);
int tallyScore(int scoreboard[][14]);

int sumFaceValues(int die[]);
int ones(int die[]);
int twos(int die[]);
int threes(int die[]);
int fours(int die[]);
int fives(int die[]);
int sixes(int die[]);

int triple(int die[]);
int quad(int die[]);
int yahtzee(int die[]);
int fullHouse(int die[]);
int smallStraight(int die[]);
int largeStraight(int die[]);
int chance(int die[]);
void bubbleSort(int die[]);
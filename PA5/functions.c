#include "header.h"

int userMenu() {
	int input;
	printf("1. Print game rules\n2. Start a game of Yahtzee\n3. Exit\n");
	scanf("%d", &input);
	return input;
}

void printRules() {
	system("cls");
	printf("The Rules of Yahtzee:\nThe scorecard used for Yahtzee is composed of two sections. An upper section and a lower section.\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63,\nthen 35 more points are added to the players overall score as a bonus. ");
	printf("The lower section contains a number of poker like combinations:\n");
	printf("|\t\tName\t\t|\t\tCombination\t\t|\t\tScore\t\t|\n");
	printf("3 of a kind\t\t\t3 dice with the same face\t\tSum of all face values\n");
	printf("4 of a kind\t\t\t4 dice with the same face\t\tSum of all face values\n");
	printf("Full house\t\t\t3 of a kind + pair\t\t\t25\n");
	printf("Small straight\t\t\t4 consecutive dice\t\t\t30\n");
	printf("Large straight\t\t\t5 consecutive dice\t\t\t40\n");
	printf("Yahtzee\t\t\t\t5 dice with the same face\t\t50\n");
	printf("Chance\t\t\t\tAny\t\t\t\t\tSum of all face values\n");
}

int roll(int rolls, int kept[], int prevRoll[]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 6; i++)
	{

	}
}

int score(int roll[]) {

}
#include "header.h"

int userMenu() {
	int input;
	printf("1. Print game rules\n2. Start a game of Yahtzee\n3. Exit\n");
	scanf("%d", &input);
	return input;
}

void initScoreboard(int scoreboard[][14]) {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (j == 13) {
				scoreboard[i][j] = 0;
			}
			else {
				scoreboard[i][j] = -1;
			}
		}
	}
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

int roll(int rolls, int kept, int die[]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5 - kept; i++)
	{
		die[i] = (rand() % 6) + 1;
	}
	return rolls + 1;
}

void printDie(int die[], int kept) {
	if (kept == -1) {
		printf("Final Roll:\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", die[i]);
		}
		printf("\n");
		return;
	}
	printf("Indexes:\n0 1 2 3 4\nRolls:\n");
	for (int i = 0; i < 5 - kept; i++)
	{
		printf("%d ", die[i]);
	}
	if (kept != 0) {
		printf("Keeping: ");
		for (int i = 0; i < kept; i++)
		{
			printf("%d ", die[4 - i]);
		}
	}
	printf("\n");
}

void keepDie(int die[], int index, int count) {
	int temp = die[index];
	die[index] = die[5 - count];
	die[5 - count] = temp;
}

void playerRoll(int player, int die[], int scoreboard[][14]) {
	int rollCount = 0;
	int kept = 0;
	int index, temp;
	char input;
	
	printf("Player %d:\n", player + 1);
	while (rollCount <= 3) {
		index = 0;
		rollCount += roll(rollCount, kept, die);
		kept = 0;

		printDie(die, kept);

		do {
			printf("Enter C to confirm roll, R to keep rolling:\n");
			scanf(" %c", &input);
		} while (input != 'C' && input != 'R');
		if (input == 'C') {
			playerScore(player, die, scoreboard);
			return;
		}

		while (0 == 0) {
			do {
				printf("Enter the index of a die to keep (-1 to confirm):\n");
				temp = scanf("%d", &index);
				if (index == -1) {
					break;
				}
			} while (index < 0 || index > 4);
			if (index == -1) {
				break;
			}
			kept += temp;
			keepDie(die, index, kept);
			printDie(die, kept);
		}
	}
	printDie(die, -1);
	playerScore(player, die, scoreboard);
}

void playerScore(int player, int die[], int scoreboard[][14]) {
	int input, score, valid;
	printf("Enter a combination:\n\t1. Sum of 1's\n\t2. Sum of 2's\n\t3. Sum of 3's\n\t4. Sum of 4's\n\t5. Sum of 5's\n\t6. Sum of 6's\n\t");
	printf("7. Three-of-a-kind\n\t8. Four-of-a-kind\n\t9. Full house\n\t10. Small straight\n\t11. Large straight\n\t12. Yahtzee\n\t13. Chance\n");
	do {
		scanf("%d", &input);
		valid = 1;
		if (scoreboard[player][input - 1] != -1) {
			valid = 0;
		}

		switch (input) {
		case 1:
			score = ones(die);
			break;
		case 2:
			score = twos(die);
			break;
		case 3:
			score = threes(die);
			break;
		case 4:
			score = fours(die);
			break;
		case 5:
			score = fives(die);
			break;
		case 6:
			score = sixes(die);
			break;
		case 7:
			score = triple(die);
			break;
		case 8:
			score = quad(die);
			break;
		case 9:
			score = fullHouse(die);
			break;
		case 10:
			score = smallStraight(die);
			break;
		case 11:
			score = largeStraight(die);
			break;
		case 12:
			score = yahtzee(die);
			break;
		case 13:
			score = chance(die);
			break;
		default:
			scanf("%d", &input);
		}
	} while (!valid);
	printf("Score: %d\n", score);
	scoreboard[player][input - 1] = score;
	Sleep(1000);
	system("cls");
}

void convArray(int die[], int converted[]) {
	for (int i = 0; i < 5; i++)
	{
		converted[die[i] - 1]++;
	}
}


int tallyScore(int scoreboard[][14]) {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (j == 5) {
				if (scoreboard[i][13] >= 63) {
					scoreboard[i][13] += 35;
				}
			}
			scoreboard[i][13] += scoreboard[i][j];
		}
	}

	if (scoreboard[0][13] <= scoreboard[1][13]) {
		return -1;
	}
	if (scoreboard[0][13] >= scoreboard[1][13]) {
		return 1;
	}
	return 0;
}

//adds dice values together
int sumFaceValues(int die[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += die[i];
	}
	return sum;
}

//sums ones
int ones(int die[]) {
	int sum = 0;
	//loop through dice and check for ones
	for (int i = 0; i < 5; i++)
	{
		//if found, increment sum
		if (die[i] == 1) {
			sum += 1;
		}
	}
	return sum;
}
//same as above, but for two
int twos(int die[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (die[i] == 2) {
			sum += 2;
		}
	}
	return sum;
}

//same as above, but for three
int threes(int die[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (die[i] == 3) {
			sum += 3;
		}
	}
	return sum;
}

//same as above, but for four
int fours(int die[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (die[i] == 4) {
			sum += 4;
		}
	}
	return sum;
}

//same as above, but for five
int fives(int die[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (die[i] == 5) {
			sum += 5;
		}
	}
	return sum;
}

//same as above, but for six
int sixes(int die[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (die[i] == 6) {
			sum += 6;
		}
	}
	return sum;
}


int triple(int die[]) {

	int score[] = { 0, 0, 0, 0, 0, 0}, found = 0, sum = 0;

	convArray(die, score);

	for (int i = 0; i < 5; i++)
	{
		if (score[i] > 2) {
			found = 1;
			break;
		}
	}

	if (found) {
		return sumFaceValues(die);
	}

	return 0;
}
int quad(int die[]) {
	int score[] = { 0, 0, 0, 0, 0, 0 }, found = 0, sum = 0;

	convArray(die, score);

	for (int i = 0; i < 5; i++)
	{
		if (score[i] > 3) {
			found = 1;
			break;
		}
	}

	if (found) {
		return sumFaceValues(die);
	}

	return 0;
}

int yahtzee(int die[]) {
	int val = die[0];
	for (int i = 1; i < 5; i++)
	{
		if (die[i] != val) {
			return 0;
		}
	}
	return 50;
}

int fullHouse(int die[]) {
	int score[] = { 0, 0, 0, 0, 0, 0 }, triple = 0, pair = 0, sum = 0;

	convArray(die, score);

	for (int i = 0; i < 5; i++)
	{
		if (score[i] == 3 || score[i] == 5) {
			triple = 1;
		}
		if (score[i] == 2 || score[i] == 5) {
			pair = 1;
		}
	}

	if (triple && pair) {
		return 25;
	}

	return 0;
}

int smallStraight(int die[]) {
	int score[] = { 0, 0, 0, 0, 0, 0 };
	int consecutive = 0;
	convArray(die, score);
	for (int i = 0; i < 6; i++)
	{
		if (score[i] >= 1) {
			consecutive += 1;
			if (consecutive >= 4) {
				return 30;
			}
		}
		if (consecutive > 0 && score[i] < 1) {
			consecutive = 0;
		}
	}
	return 0;
}

int largeStraight(int die[]) {
	int score[] = { 0, 0, 0, 0, 0, 0 };
	convArray(die, score);
	int start = 0;
	if (score[0] == 0) {
		start = 1;
	}
	for (int i = start; i < 6; i++)
	{
		if (score[i] != 1) {
			return 0;
		}
	}
	return 30;
}

int chance(int die[]) {
	return sumFaceValues(die);
}

void bubbleSort(int die[]) {
	int temp, swapped;
	do {
		swapped = 0;
		for (int i = 1; i < 5; i++)
		{
			if (die[i - 1] > die[i]) {
				swapped++;
				temp = die[i];
				die[i] = die[i - 1];
				die[i - 1] = temp;
			}
		}
	} while (swapped != 0);
}
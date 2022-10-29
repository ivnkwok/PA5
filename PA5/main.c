#include "header.h"

int main(void) {
	while (0 == 0) {
		int input = userMenu();
		int player = 0;
		int round = 1;
		int winner = 0;
		int die[] = { 6, 3, 3, 4, 5 };
		int scoreboard[2][14];
		initScoreboard(scoreboard);
		while (input != 2) {
			if (input == 1) {
				printRules();
				printf("\n");
				input = userMenu();
			}
			if (input == 3) {
				printf("Adios");
				return 0;
			}
		}
		system("cls");
		while (round < 14) {
			printf("Round %d\n", round);
			playerRoll(player, die, scoreboard);
			if (player == 1) {
				round++;
				player = 0;
			}
			else {
				player = 1;
			}
		}
		winner = tallyScore(scoreboard);
		if (winner == -1) {
			printf("Player 1 wins!");
		}
		if (winner == 0) {
			printf("You tied somehow...");
		}
		if (winner == 1) {
			printf("Player 2 wins!");
		}
		printf("Enter any key to continue playing:\n");
		scanf(" %c", &input);
		
	}
}
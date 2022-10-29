#include "header.h"

int main(void) {
	int input = userMenu();
	char temp;
	int die[] = { 0, 0, 0, 0, 0 };

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
	
}
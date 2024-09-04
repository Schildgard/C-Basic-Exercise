#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER_KEY 13

int main() {

	char* userName = GetUserName();
	int chosenNumber;
	printf("Your Username is %s", userName);
	chosenNumber = ChooseOption();
	printf("You chose option %i", chosenNumber);

	return 0;
}

char* GetUserName() {
	printf("Hello User. Please enter your name: \n");

	int input[1000];
	fgets(input, sizeof(input), stdin);

	return input;
}

int ChooseOption() {
	int currentOption = 1;
	int select;

	while (1) {
		printf("\033[H\33[J");
		printf(currentOption == 1 ? "> Option A\n" : "Option A\n");
		printf(currentOption == 2 ? "> Option B\n" : "Option B\n");
		printf(currentOption == 3 ? "> Option C\n" : "Option C\n");


		select = _getch();

		if (select == 224) {
			select = _getch();
			switch (select) {

			case UP_ARROW:
				if (currentOption > 1) currentOption--;
				break;
			case DOWN_ARROW:
				if (currentOption < 3) currentOption++;
				break;
			}
		}
		else if (select = ENTER_KEY) { return currentOption; }
	}
}
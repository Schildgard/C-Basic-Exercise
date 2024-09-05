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


	char* optionA = "Radagon";
	char* optionB = "Marika";
	char* optionC = "Maliketh";

	chosenNumber = ChooseOption(optionA, optionB, optionC);
	//chosenNumber = ChooseOptionTEST();
	printf("You chose option %i", chosenNumber);


	return 0;
}

char* GetUserName() {
	printf("Hello User. Please enter your name: \n");

	int input[1000];
	fgets(input, sizeof(input), stdin);

	return input;
}

int ChooseOptionTEST() {
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
		} else if (select = ENTER_KEY) { return currentOption;}
	}
}


int ChooseOption(char _str1[], char _str2[], char _str3[]) {

		//printf(currentOption == 1 ? ">   %s \n", _str1 :"%s\n", _str1);
		////printf("\n");
		//printf(currentOption == 2 ? (">   %sz\n", _str2) : (_str2));
		//printf(currentOption == 3 ? (">   %sz\n", _str3) :(_str3));

		//for (int i = 0; i < 3; i++)
		//{
		//	if (currentOption == i) {
		//		printf(">  %sz\n", );
		//	}
		//}

	int currentOption = 1;
	int select;

	while (1)
	{
		printf("\033[H\33[J");

		if (currentOption == 1) {

			printf(">    %s\n", _str1);
		}
		else printf("%s \n", _str1);

		if (currentOption == 2) {

			printf(">    %s\n", _str2);
		}
		else printf("%s \n", _str2);

		if (currentOption == 3) {

			printf(">    %s\n", _str3);
		}
		else printf("%s \n", _str3);


		select = _getch();

		if (select == 224) {
			select = _getch();
			switch (select) {
			case UP_ARROW:
				//currentOption > 1 ? -1 : 3; //Ternary Operator: is current option bigger than 1 ? If yes, decrease, if no: go to end
				if (currentOption > 1) currentOption--;
				break;
			case DOWN_ARROW:
				//currentOption < 3 ? +1 : 1; //Ternary Operator: is current option smaller than 3 ? If yes, increase, if no: go to start
				if (currentOption < 3) currentOption++;
				break;
			}
		} else if (select = ENTER_KEY) { return currentOption; }
	}
}


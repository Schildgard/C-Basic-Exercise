#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "main.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER_KEY 13

int main() {

	// Ask User Name
	char* userName = GetUserName();
	int chosenNumber;
	printf("Your Username is %s", userName);

	// Declare Options
	char* optionA = "Radagon";
	char* optionB = "Marika";
	char* optionC = "Maliketh";
	char* question1 = "Who was a Champion of the Golden Order?";

	// Let User choose Option
	chosenNumber = ChooseOption(optionA, optionB, optionC, question1);
	printf("You chose option %i", chosenNumber);

	return 0;
}

char* GetUserName() {
	printf("Hello User. Please enter your name: \n");

	int input[1000];
	fgets(input, sizeof(input), stdin);

	return input;
}



int ChooseOption(char _str1[], char _str2[], char _str3[], char _question[]) {

	//First memorize size of strings
	int sizeOfStr1 = strlen(_str1);
	int sizeOfStr2 = strlen(_str2);
	int sizeOfStr3 = strlen(_str3);

	//Allocate Memory for an array that stores pointer to the strings
	char** strArr = (char**)malloc(3 * sizeof(char*));

	//declar content of string Array
	strArr[0] = _str1;
	strArr[1] = _str2;
	strArr[2] = _str3;

	// Let user select between indices
	int currentOption = 0;
	int select;

	while (1)
	{
		printf("\033[H\33[J"); //Clear Console
		printf("%s\n", _question);
		//iterate through string Array and print the avaiable options, highlighting the selected one
		for (int i = 0; i < 3; i++)
		{
			if (currentOption == i) {
				printf(">  %s\n", strArr[i]);
			}
			else {
				printf("%s\n", strArr[i]);
			}
		}

		select = _getch(); //Wait for user Input

		if (select == 224) { // check if user Input is an ARROW BUTTON
			select = _getch(); //check if input was up or down
			switch (select) {
			case UP_ARROW:
				//currentOption > 1 ? -1 : 3; //Ternary Operator: is current option bigger than 1 ? If yes, decrease, if no: go to end
				if (currentOption > 0) currentOption--;
				break;
			case DOWN_ARROW:
				//currentOption < 3 ? +1 : 1; //Ternary Operator: is current option smaller than 3 ? If yes, increase, if no: go to start
				if (currentOption < 2) currentOption++;
				break;
			}
		}
		else if (select = ENTER_KEY) { return currentOption+1; } //if enter was pressed, return from this function and return the selected option +1, so the index gets translanted into more user friendly context
	}
}


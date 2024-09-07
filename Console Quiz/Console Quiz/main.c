#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "main.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER_KEY 13

int main() {
	int userScore = 0;
	// Ask User Name
	char* userName = GetUserName();
	printf("Your Username is %s", userName);

	Riddle task1 = { "Radagon", "Marika","Maliketh", "Who was a Champion of the Golden Order?", 1 };
	Riddle task2 = { "Godefroy", "Godrick", "Godfrey", "By what name goes the first Elden Lord?", 3 };
	Riddle task3 = { "The Three Fingers", "Empyreans", "The Two Fingers", "Which entitites are messengers of the Greater Will?", 3 };


	AskRiddle(task1, userScore);
	_getch();

	AskRiddle(task2, userScore);
	_getch();

	AskRiddle(task3, userScore);
	_getch();

	printf("\033[H\33[J"); //Clear Console
	printf("Your Highscore is %i", userScore);

	return 1;
}

char* GetUserName() {
	printf("Hello User. Please enter your name: \n");

	int input[1000];
	fgets(input, sizeof(input), stdin);

	return input;
}




int AskRiddle(Riddle _riddle, int _score) {
	//Allocate Memory for an array that stores pointer to the strings
	char** strArr = (char**)malloc(3 * sizeof(char*));

	//declar content of string Array
	strArr[0] = _riddle.optionA;
	strArr[1] = _riddle.optionB;
	strArr[2] = _riddle.optionC;

	// Let user select between indices
	int currentOption = 0;
	int select;

	while (1)
	{
		printf("\033[H\33[J"); //Clear Console
		printf("%s\n", _riddle.question);
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
		else if (select == ENTER_KEY) { //if enter was pressed, return from this function. Add +1 to current option to translate index to userfriendly output
			if (currentOption + 1 == _riddle.truth) {
				_score += 10;
				printf("Your Answer is correct.\n");
			}
			else printf(" Wrong Answer.\n");

			return currentOption + 1;
		}
	}

}


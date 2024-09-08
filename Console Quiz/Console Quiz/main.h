#pragma once


char* GetUserName();
typedef struct Riddle {
	char* optionA;
	char* optionB;
	char* optionC;
	char* question;
	int truth;
}Riddle;
int AskRiddle(Riddle _riddle, int* _score);

void IterateThroughRiddles(Riddle _riddle[], int* _score);
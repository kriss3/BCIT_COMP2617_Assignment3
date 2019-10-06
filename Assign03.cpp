/*
Assignment 03;
Krzysztof Szczurowski
BCIT: A01013054
October 1st 2019
*/

#include <iostream>
#include <string>

using namespace std;

void multiplication();			// function prototype for multiplication operations;
void correctMessage();		// function prototype to randomize display messages for correct answers;
void incorrectMessage();		// function prototype to randomize display messages for incorrect answers;

int main()
{
	cout << "Enter -1 to End." << endl;
	multiplication();
	cout << "\nThat's all for now. Bye.\n";
	return 0;
}

//method to perform multiplication operation;
void multiplication() 
{
	//setting up required variables;
	int exit = 0;
	int result = 0;
	int val1 = 0;
	int val2 = 0;


	do
	{
		//setting up random valus for multiplication operation;
		val1 = rand() % 10;
		val2 = rand() % 10;
		
		cout << "How much is " << val1 << " times " << val2 << " (-1 to End) ? ";
		cin >> result;

		while (result != val1 * val2 && result >= 0)	// looping until the anser is correct;
		{
			incorrectMessage();	// calling incorrectMessage() to randomly display response message;
			cin >> result;
		};
		
		if (result == val1 * val2 && result >= 0)	// checking if user answert is correct and > 0
		{
			correctMessage();		//calling correctMessage() to randomly display response message;
		}
		
		if (result < 0)			// checking for exit condition (user enters -1)
		{
			exit = -1;
		}
	} while (exit != -1);		// exit condition based user entering -1;
}

void correctMessage() 
{
	//enum of possible message when user answer the question correctly;
	enum class Answer {
		CORRECT = 0,
		VERYGOOD,
		WAYTOGO,
		FANTASTIC,
		THEBEST
	};

	//randomizing selection of the enum message;
	Answer a = static_cast<Answer>(rand() % 5);
	
	//base on the randomization of the enum message selecting the actual message
	switch (a)
	{
	case Answer::CORRECT:
		cout << "Correct\n\n";
		break;
	case Answer::VERYGOOD:
		cout << "Very Good!!!\n\n";
		break;
	case Answer::WAYTOGO:
		cout << "Good. Way To Go!!!\n\n";
		break;
	case Answer::FANTASTIC:
		cout << "Correct. You are fantastic!!!\n\n";
		break;
	case Answer::THEBEST:
		cout << "Good! You Are The Best\n\n";
		break;
	default:
		cout << "Buuu something went wrong!\n\n";  //include default option as a good practice;
		break;
	}
}	//end correctMessage();

void incorrectMessage() 
{
	//enum of possible message when user answer is incorrect;
	enum class Answer {
		INCORRECT = 0,
		NOTSOGREAT,
		NOTGOOD,
		NOTQUITERIGHT,
		WRONG
	};

	//randomizing selection of the enum message (incorrect message);
	Answer a = static_cast<Answer>(rand() % 5);
	
	//base on the randomization of the enum message selecting the actual message
	switch (a)
	{
	case Answer::INCORRECT:
		cout << "Incorrect. Try one more time.\n? ";
		break;
	case Answer::NOTSOGREAT:
		cout << "Not so great. One more time.\n? ";
		break;
	case Answer::NOTGOOD:
		cout << "Not good this time. Try again\n? ";
		break;
	case Answer::NOTQUITERIGHT:
		cout << "Not quite right. Try one more time.\n? ";
		break;
	case Answer::WRONG:
		cout << "You got it wrong this time. Try again.\n? ";
		break;
	default:
		cout << "Buuu something went wrong!\n? ";		//include default option as a good practice;
		break;
	}	//end incorrectMessage();
}	//end main;
/*
Assignment 03;
Krzysztof Szczurowski
October 10th 2019

*/

#include <iostream>
#include <string>

using namespace std;

void multiplication(); // function prototype
void correctMessage(); // function prototype
void incorrectMessage(); // function prototype
int doRand();

int main()
{
	cout << "Enter -1 to End." << endl;
	multiplication();
	cout << "That's all for now. Bye.\n";
	return 0;
}

void multiplication() 
{
	int exit = 0;
	int result = 0;
	int val1 = 0;
	int val2 = 0;


	do
	{
		val1 = doRand();
		val2 = doRand();
		
		cout << "How much is " << val1 << " times " << val2 << " (-1 to End) ? ";
		cin >> result;

		while (result != val1 * val2 && result >= 0)
		{
			incorrectMessage();
			cin >> result;
		};
		
		if (result == val1 * val2 && result > 0)
		{
			correctMessage();
		}
		
		if (result < 0)
		{
			exit = -1;
		}
	} while (exit != -1);
}

void correctMessage() 
{
	enum class Answer {
		Correct = 0,
		Very_Good,
		Way_To_Go,
		Fantastic,
		You_Are_The_Best
	};

	Answer a = static_cast<Answer>(rand() % 5);
	switch (a)
	{
	case Answer::Correct:
		cout << "Correct\n\n";
		break;
	case Answer::Very_Good:
		cout << "Very Good!!!\n\n";
		break;
	case Answer::Way_To_Go:
		cout << "Way To Go!!!\n\n";
		break;
	case Answer::Fantastic:
		cout << "Fantastic!!!\n\n";
		break;
	case Answer::You_Are_The_Best:
		cout << "You Are The Best\n\n";
		break;
	default:
		cout << "Buuu something went wrong!\n\n";
		break;
	}
}

void incorrectMessage() 
{
	enum class Answer {
		INCORRECT = 0,
		NOT_SO_GREAT,
		NOT_GOOD,
		NOT_QUITE_WRIGHT,
		WRONG
	};

	Answer a = static_cast<Answer>(rand() % 5);
	switch (a)
	{
	case Answer::INCORRECT:
		cout << "Incorrect. Try one more time.\n? ";
		break;
	case Answer::NOT_SO_GREAT:
		cout << "Not so great. One more time.\n? ";
		break;
	case Answer::NOT_GOOD:
		cout << "Not good this time. Try again\n? ";
		break;
	case Answer::NOT_QUITE_WRIGHT:
		cout << "Not quite wright. Try one more time.\n? ";
		break;
	case Answer::WRONG:
		cout << "You got it wrong this time. Try again.\n? ";
		break;
	default:
		cout << "Buuu something went wrong!\n? ";
		break;
	}
}

int doRand()
{
	return rand() % 9 + 1;
}
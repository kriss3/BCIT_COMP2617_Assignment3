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
	enum Answer {
		Correct,
		Very_Good,
		Way_To_Go,
		Fantastic,
		You_Are_The_Best,
		Answer_Count
	};

	Answer a = static_cast<Answer>(rand() % Answer_Count);
	switch (a)
	{
	case Correct:
		cout << "Correct\n\n";
		break;
	case Very_Good:
		cout << "Very Good!!!\n\n";
		break;
	case Way_To_Go:
		cout << "Way To Go!!!\n\n";
	case Fantastic:
		cout << "Fantastic!!!\n\n";
		break;
	case You_Are_The_Best:
		cout << "You Are The Best\n\n";
		break;
	default:
		cout << "Buuu something went wrong!\n\n";
		break;
	}
}

void incorrectMessage() 
{
	cout << "Wrong! Try again\n? ";
}

int doRand()
{
	return rand() % 9 + 1;
}
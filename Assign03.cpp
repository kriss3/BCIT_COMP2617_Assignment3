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
	cout << "Correct!\n\n";
}

void incorrectMessage() 
{
	cout << "Wrong! Try again\n? ";
}

int doRand()
{
	return rand() % 9 + 1;
}
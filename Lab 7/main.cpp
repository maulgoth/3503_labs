#include <iostream>
#include <map>
#include <random>
#include <ctime>
// #include "extrafile.h"
using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides) {
	map<int,int> rolls;
	for (int i = 0; i < numberOfRolls; i++) {
			int x = Random(1, numberOfSides);
			
		}
}

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);


		cout << "Number of times to roll the die: ";
      // user input
		int numberOfRolls;
		cin >> numberOfRolls;

		cout << "Number of sides on this die: ";
      // user input
		int numberOfSides;
		cin >> numberOfSides;

		// Roll Dice
		RollDice(numberOfRolls, numberOfSides);
	}
	else if (option == 2)
	{
	   // Load the states
	   
	   // Get input for option 1 (show all states) or 2 (do a search for a particular state)

	}

	cout << endl;

	return 0;
}

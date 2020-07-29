// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
// #include "extrafile.h"
using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

class State
{
private:
	string name;
	int perCapitaIncome;
	int population;
	int medianHouseholdIncome;
	int numberOfHouseholds;
public:
	State(string _name, int _perCapitaIncome, int _population, int _medianHouseholdIncome, int _numberOfHouseholds) {
		name = _name;
		perCapitaIncome = _perCapitaIncome;
		population = _population;
		medianHouseholdIncome = _medianHouseholdIncome;
		numberOfHouseholds = _numberOfHouseholds;
	};
	void printState() {
		cout << name << endl;
		cout << "Population: " << population << endl;
		cout << "Per Capita Income: " << perCapitaIncome << endl;
		cout << "Median Household Income: " << medianHouseholdIncome << endl;
		cout << "Number of Households: " << numberOfHouseholds << endl;
	};
};

void RollDice(int numberOfRolls, int numberOfSides)
{
	// create map
	map<int, int> rolls;

	// init each possible roll with 0
	for (int i = 1; i < numberOfSides + 1; i++)
		rolls[i] = 0;

	// generate random number, increment value in map
	for (int i = 0; i < numberOfRolls; i++)
	{
		int x = Random(1, numberOfSides);
		rolls[x] = rolls[x] + 1;
	}

	// iterate over each and print
	map<int, int>::iterator iter;
	for (iter = rolls.begin(); iter != rolls.end(); iter++)
		cout << iter->first << ": " << iter->second << endl;
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
		map<string, State> states;
		string name;
		int perCapitaIncome;
		int population;
		int medianHouseholdIncome;
		int numberOfHouseholds;

		ifstream file("states.csv");
		string line;

		getline(file, line); // skip first line

		while (getline(file, line)) {
			stringstream stream(line);
			string item;
			while (getline(stream, item, ',')) {
				name = item;
				getline(stream, item, ',');
				perCapitaIncome = stoi(item);
				getline(stream, item, ',');
				population = stoi(item);
				getline(stream, item, ',');
				medianHouseholdIncome = stoi(item);
				getline(stream, item, ',');
				numberOfHouseholds = stoi(item);
				State tempState(name, perCapitaIncome, population, medianHouseholdIncome, numberOfHouseholds);
				states.emplace(name, tempState);
			}

		}

		// Get input for option 1 (show all states) or 2 (do a search for a particular state)
		int stateChoice;
		cout << "1. Print all states" << endl;
		cout << "2. Search for a state" << endl;
		cin >> stateChoice;
		
		if (stateChoice == 1) {
			map<string, State>::iterator iter;
			for (iter = states.begin(); iter != states.end(); iter++)
				iter->second.printState();
		}
		
		if (stateChoice == 2) {
			string stateSearch;
			cin >> stateSearch;

			// Check if search exists, if not: warn, if so: print
			if (states.find(stateSearch) == states.end())
				cout << "No match found for " << stateSearch << endl;
			else
				states.find(stateSearch)->second.printState();
		}
	}
	return 0;
}

#pragma once
#include <string>
#include <vector>
#include "Showroom.h"
using namespace std;

class Dealership
{
	string name;
	unsigned int capacity;
	vector<Showroom> showrooms;

public:
	Dealership(string _name = "Generic Dealership", unsigned int _capacity = 0);

	void AddShowroom(Showroom _showroom);

	void ShowInventory();

	float GetAveragePrice();

};


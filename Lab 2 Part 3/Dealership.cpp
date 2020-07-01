// My former submissions were made before I discovered the QUITE HELPFUL PDF!
// Classes, functions, and data types have been altered to fit the PDF specs.
//
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online


#include <iostream>
#include <string>
#include "Dealership.h"
using namespace std;

Dealership::Dealership(string _name, unsigned int _capacity)
{
	name = _name;
	capacity = _capacity;
}

void Dealership::AddShowroom(Showroom _showroom)
{
	if (showrooms.size() == capacity) {
		cout << "Dealership is full, can't add another showroom!" << endl;
	}
	else {
		showrooms.push_back(_showroom);
	}
}

void Dealership::ShowInventory()
{
	if (showrooms.size() == 0) {
		cout << name << " is empty!" << endl;
	}
	else {
		// Output inventory
		for (unsigned int i = 0; i < showrooms.size(); ++i) {
			showrooms.at(i).ShowInventory();
			cout << endl;
		}
	}
	
	// Print average
	cout << "Average car price: $" << GetAveragePrice();
}

float Dealership::GetAveragePrice()
{
	float total = 0;
	float average = 0;
	int count = 0;

	for (unsigned int i = 0; i < showrooms.size(); ++i) {
		count = count + showrooms.at(i).GetVehicleList().size();
		total = total + showrooms.at(i).GetInventoryValue();
	}
	if (count == 0) {
		average = 0.00;
	}
	else {
		average = total / count;
	}

	return average;
}
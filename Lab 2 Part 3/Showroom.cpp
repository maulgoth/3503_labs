#include <iostream>
#include <string>
#include <vector>
#include "Showroom.h"
using namespace std;

Showroom::Showroom(string _name, unsigned int _capacity)
{
	name = _name;
	capacity = _capacity;
}

float Showroom::GetInventoryValue()
{
	float value = 0;
	for (unsigned int i = 0; i < vehicles.size(); ++i) {
		value = value + vehicles.at(i).GetPrice();
	}
	return value;
}

void Showroom::AddVehicle(Vehicle _vehicle)
{
	if (vehicles.size() == capacity) {
		cout << "Showroom is full! Cannot add " << _vehicle.GetYearMakeModel() << endl;
	}
	else {
		vehicles.push_back(_vehicle);
	}
}

void Showroom::ShowInventory()
{
	if (capacity == 0) {
		cout << "Unnamed Showroom is empty!" << endl;
	}
	else {
		cout << "Vehicles in " << name << endl;
		for (unsigned int i = 0; i < vehicles.size(); ++i) {
			vehicles.at(i).Display();
		}
	}
}

vector<Vehicle> Showroom::GetVehicleList()
{
	return vehicles;
}
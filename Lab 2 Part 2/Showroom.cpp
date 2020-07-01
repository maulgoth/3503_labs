#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Vehicle.h"
#include "Showroom.h"

Showroom::Showroom()
{
	name = "Unnamed Showroom";
	size = 0;
	value = 0;

}

Showroom::Showroom(string _name, unsigned int _size)
{
	name = _name;
	size = _size;
	value = 0;
}

double Showroom::GetInventoryValue()
{
	for (unsigned int i = 0; i < size; ++i) {
		value = value + vehicles.at(i).GetPrice();
	}
	return value;
}

void Showroom::AddVehicle(Vehicle _vehicle)
{
	if (vehicles.size() == size) {
		cout << "Showroom is full! Cannot add " << _vehicle.GetYearMakeModel() << endl;
	}
	else {
		vehicles.push_back(_vehicle);
	}
}

void Showroom::ShowInventory()
{
	if (size == 0) {
		cout << "Unnamed Showroom is empty!" << endl;
	}
	else {
		cout << "Vehicles in " << name << endl;
		for (unsigned int i = 0; i < size; ++i) {
			vehicles.at(i).Display();
		}
	}
}
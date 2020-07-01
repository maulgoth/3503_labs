#pragma once
#include <string>
#include <vector>
using namespace std;

class Showroom
{
	string name;
	unsigned int size;
	double value;
	vector<Vehicle> vehicles;

public:
	Showroom();

	Showroom(string _name, unsigned int _size);

	double GetInventoryValue();

	void AddVehicle(Vehicle _vehicle);

	void ShowInventory();


};
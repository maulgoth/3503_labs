#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"
using namespace std;

class Showroom
{
	string name;
	unsigned int capacity;
	vector<Vehicle> vehicles;

public:
	Showroom(string _name = "Unnamed Showroom", unsigned int _capacity = 0);

	vector<Vehicle> GetVehicleList();

	float GetInventoryValue();

	void AddVehicle(Vehicle _vehicle);

	void ShowInventory();
};
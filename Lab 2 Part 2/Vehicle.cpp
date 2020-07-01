#include <iostream>
#include <string>
using namespace std;

#include "Vehicle.h"

Vehicle::Vehicle()
{
	make = "COP3503";
	model = "Rust Bucket";
	year = 1900;
	price = 0.00;
	mileage = 0;
}

Vehicle::Vehicle(string _make, string _model, int _year, int _price, int _mileage)
{
	make = _make;
	model = _model;
	year = _year;
	price = _price;
	mileage = _mileage;
}

double Vehicle::GetPrice()
{
	return price;
}

int Vehicle::GetMileage()
{
	return mileage;
}

string Vehicle::GetYearMakeModel()
{
	string yearMakeModel = to_string(year) + " " + make + " " + model;
	return yearMakeModel;
}

void Vehicle::Display()
{
	cout << GetYearMakeModel() << " $" << GetPrice() << " " << GetMileage() << endl;
}
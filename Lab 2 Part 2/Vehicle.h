#pragma once
#include <string>
using namespace std;

class Vehicle
{
	string make;
	string model;
	int year;
	double price;
	int mileage;

public:
	Vehicle();

	Vehicle(string _make, string _model, int _year, int _price, int _mileage);

	double GetPrice();

	int GetMileage();

	string GetYearMakeModel();

	void Display();

};
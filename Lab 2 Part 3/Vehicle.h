#pragma once
#include <string>
using namespace std;

class Vehicle
{
	string make;
	string model;
	int year;
	float price;
	int mileage;

public:
	Vehicle();

	Vehicle(string _make, string _model, int _year, float _price, int _mileage);

	float GetPrice();

	int GetMileage();

	string GetYearMakeModel();

	void Display();

};
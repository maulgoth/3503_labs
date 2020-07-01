#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#include "leaker.h"

class Weapon {
public:
	Weapon(string _weaponName, int _powerRating, float _powerC) {
		weaponName = _weaponName;
		powerRating = _powerRating;
		powerC = _powerC;
	}
	string GetName() {
		return weaponName;
	}
	int GetPowerRating() {
		return powerRating;
	}
	float GetPowerC() {
		return powerC;
	}
private:
	string weaponName;
	int powerRating;
	float powerC;
};

class Ship {
public:
	Ship(string _shipName, string _shipClass, short _shipLength, int _shieldCap, float _warpSpeed, int _weaponCount);
	void AddWeapon(string _weaponName, int _powerRating, float _powerC);
	int GetWeaponPower(int index);
	int GetWeaponCount();
	int GetFirePower();
	void Print();
private:
	string shipName;
	string shipClass;
	short shipLength;
	int shieldCap;
	float warpSpeed;
	int weaponCount;
	vector<Weapon> weapons;
};

Ship::Ship(string _shipName, string _shipClass, short _shipLength, int _shieldCap, float _warpSpeed, int _weaponCount) {
	shipName = _shipName;
	shipClass = _shipClass;
	shipLength = _shipLength;
	shieldCap = _shieldCap;
	warpSpeed = _warpSpeed;
	weaponCount = _weaponCount;

}

void Ship::AddWeapon(string _weaponName, int _powerRating, float _powerC) {
	weapons.push_back(Weapon(_weaponName, _powerRating, _powerC));
}

void Ship::Print() {
	cout << "Name: " << shipName << endl;
	cout << "Class: " << shipClass << endl;
	cout << "Length: " << shipLength << endl;
	cout << "Shield capacity: " << shieldCap << endl;
	cout << "Maximum Warp: " << warpSpeed << endl;
	cout << "Armaments:" << endl;
	if (weaponCount == 0) {
		cout << "Unarmed" << endl;
	}
	else {
		for (unsigned int i = 0; i < weaponCount; i++) {
			cout << weapons.at(i).GetName() << ", " << weapons.at(i).GetPowerRating() << ", " << weapons.at(i).GetPowerC() << endl;
		}
		cout << "Total firepower: " << GetFirePower() << endl;
	}
	cout << endl;
}

int Ship::GetWeaponPower(int index) {
	return weapons.at(index).GetPowerRating();
}

int Ship::GetFirePower() {
	int firePower = 0;
	for (unsigned int i = 0; i < weaponCount; i++) {
		firePower += weapons.at(i).GetPowerRating();
	}
	return firePower;
}

int Ship::GetWeaponCount() {
	return weaponCount;
}

vector<Ship> ReadDataFromFile(string path) {
	vector<Ship> tempShips;
	ifstream file(path, ios_base::binary);
	if (file.is_open()) {
		int count;
		int shipNameLength;
		string shipName;
		int shipClassLength;
		string shipClass;
		short shipLength;
		int shieldCap;
		float warpSpeed;
		int weaponCount;
		int weaponNameLength;
		string weaponName;
		int weaponPower;
		float weaponC;

		file.read((char*)&count, 4);
		for (unsigned int i = 0; i < count; i++) {
			//cout << "i is currently: " << i << endl;
			file.read((char*)&shipNameLength, 4);
			char* nameTemp = new char[shipNameLength];
			file.read(nameTemp, shipNameLength * sizeof(nameTemp[0]));
			shipName = nameTemp;
			delete[] nameTemp;
			file.read((char*)&shipClassLength, 4);
			char* classTemp = new char[shipClassLength];
			file.read(classTemp, shipClassLength * sizeof(classTemp[0]));
			shipClass = classTemp;
			delete[] classTemp;
			file.read((char*)&shipLength, 2);
			file.read((char*)&shieldCap, 4);
			file.read((char*)&warpSpeed, 4);
			file.read((char*)&weaponCount, 4);

			Ship temp = Ship(shipName, shipClass, shipLength, shieldCap, warpSpeed, weaponCount);
			if (weaponCount > 0) {
				for (unsigned int j = 0; j < weaponCount; j++) {
					file.read((char*)&weaponNameLength, 4);
					char* nameTemp = new char[weaponNameLength];
					file.read(nameTemp, weaponNameLength * sizeof(nameTemp[0]));
					weaponName = nameTemp;
					delete[] nameTemp;
					file.read((char*)&weaponPower, 4);
					file.read((char*)&weaponC, 4);
					temp.AddWeapon(weaponName, weaponPower, weaponC);
				}
			}
			tempShips.push_back(temp);
		}
		file.close();
	}
	return tempShips;
}
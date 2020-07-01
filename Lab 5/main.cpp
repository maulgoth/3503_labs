#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

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
		for (int i = 0; i < weaponCount; i++) {
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
	for (int i = 0; i < weaponCount; i++) {
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

		// Count
		file.read((char*)&count, 4);
		for (int i = 0; i < count; i++) {
			// Name
			file.read((char*)&shipNameLength, 4);
			char* nameTemp = new char[shipNameLength];
			file.read(nameTemp, shipNameLength * sizeof(nameTemp[0]));
			shipName = nameTemp;
			delete[] nameTemp;
			// Class
			file.read((char*)&shipClassLength, 4);
			char* classTemp = new char[shipClassLength];
			file.read(classTemp, shipClassLength * sizeof(classTemp[0]));
			shipClass = classTemp;
			delete[] classTemp;
			// Length
			file.read((char*)&shipLength, 2);
			// Shield Capacity
			file.read((char*)&shieldCap, 4);
			// Warp Speed
			file.read((char*)&warpSpeed, 4);
			// Weapon Count
			file.read((char*)&weaponCount, 4);
			// Create Ship
			Ship temp = Ship(shipName, shipClass, shipLength, shieldCap, warpSpeed, weaponCount);
			// Fill Weapons
			if (weaponCount > 0) {
				for (int j = 0; j < weaponCount; j++) {
					file.read((char*)&weaponNameLength, 4);
					char* weapTemp = new char[weaponNameLength];
					file.read(weapTemp, weaponNameLength * sizeof(weapTemp[0]));
					weaponName = weapTemp;
					delete[] weapTemp;
					file.read((char*)&weaponPower, 4);
					file.read((char*)&weaponC, 4);
					temp.AddWeapon(weaponName, weaponPower, weaponC);
				}
			}
			// Push Ship to Temp Array
			tempShips.push_back(temp);
		}
		file.close();
	}
	// Return Temp Array
	return tempShips;
}

int main()
{
	// --------- Load MENU -------------- //
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;
	vector<Ship> ships;

	// --------- Load MENU Logic -------------- //
	if (option == 1) {
		ships = ReadDataFromFile("friendlyships.shp");
	}
	else if (option == 2) {
		ships = ReadDataFromFile("enemyships.shp");
	}
	else if (option == 3) {
		ships = ReadDataFromFile("friendlyships.shp");
		vector<Ship> ships2 = ReadDataFromFile("enemyships.shp");
		ships.insert(ships.end(), ships2.begin(), ships2.end());
	}
	else {
		cout << "INVALID CHOICE!";
	}

	// --------- Action MENU -------------- //
	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;
	cin >> option;

	// --------- Action MENU Logic -------------- 

	// Print All
	if (option == 1) {
		for (unsigned int i = 0; i < ships.size(); i++) {
			ships.at(i).Print();
		}
	}
	// Strongest Weapon
	else if (option == 2) {
		int strongest = 0;
		int power = 0;
		// Loop each ship and each weapon
		for (unsigned int i = 0; i < ships.size(); i++) {
			if (ships.at(i).GetWeaponCount() != 0) {
				for (int j = 0; j < ships.at(i).GetWeaponCount(); j++) {
					int x = ships.at(i).GetWeaponPower(j);
					if (x > power) {
						power = x;
						strongest = i;
					}
				}
			}

		}
		ships.at(strongest).Print();
	}
	// Strongest overall
	else if (option == 3) {
		int strongest = 0;
		int power = 0;
		// Loop each ship
		for (unsigned int i = 0; i < ships.size(); i++) {
			if (ships.at(i).GetWeaponCount() != 0) {
				int x = ships.at(i).GetFirePower();
				if (x > power) {
					power = x;
					strongest = i;
				}
			}
		}
		ships.at(strongest).Print();
	}
	// Weakest
	else if (option == 4) {
		int weakest = 0;
		int power = 999999999;
		// Loop each ship
		for (unsigned int i = 0; i < ships.size(); i++) {
			if (ships.at(i).GetWeaponCount() != 0) {
				int x = ships.at(i).GetFirePower();
				if (i == 0) {
					power = x;
					weakest = i;
				}
				else if (x < power) {
					power = x;
					weakest = i;
				}
			}
		}
		ships.at(weakest).Print();
	}
	// Unarmed
	else if (option == 5) {
		for (unsigned int i = 0; i < ships.size(); i++) {
			if (ships.at(i).GetWeaponCount() == 0) {
				ships.at(i).Print();
			}
		}
	}

	return 0;
}
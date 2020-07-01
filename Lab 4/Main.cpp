// Jeremy DePoyster - COP3503 Summer 2020 - UF Online
// All code completely original, inspired by Professor Joshua Fox's lectures,
// Or AS CITED in comments.

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Lego {
public:
	Lego(int _number, string _theme, string _name, int _minifigs, int _pieces, double _price) {
		number = _number;
		theme = _theme;
		name = _name;
		minifigs = _minifigs;
		pieces = _pieces;
		price = _price;
	}
	int getNumber() const { return number; }
	string getTheme() const { return theme; }
	string getName() const { return name; }
	int getMinifigs() const { return minifigs; }
	int getPieces() const { return pieces; }
	double getPrice() const { return price; }
	void printLego() {
		cout << "Name: " << name << endl;
		cout << "Number: " << number << endl;
		cout << "Theme: " << theme << endl;
		cout << "Price: $" << price << endl;
		cout << "Minifigures: " << minifigs << endl;
		cout << "Piece count: " << pieces << endl;
	}
	void printLegoShort() {
		cout << number << " " << name << " $" << price << endl;
	}
private:
	int number = -1;
	string theme = "theme";
	string name = "name";
	int minifigs = -1;
	int pieces = -1;
	double price = 0.00;
};



/*************************************************************************
/ CITATION FOR ReadDataFromFile() method:
/ String Stream and Temporary Token came from
/ Professor Joshua Fox Lecture as well as:
/ 
/ Article: HOW TO SPLIT A STRING IN C++
/ Site: MartinBroadhurst
/ Aurhor: Martin Broadhurst
/ URL: http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
************************************************************************/

vector<Lego> ReadDataFromFile(string path) {
	int number;
	string theme;
	string name;
	int minifigs;
	int pieces;
	double price;
	vector<Lego> tempLegoList;
	ifstream file(path);
	string line;

	getline(file, line); // skip first line of csv
	
	while (getline(file, line)) {
		stringstream stream(line);
		string token;
		while (getline(stream, token, ',')) {
			// Store csv data in vars
			number = stoi(token);
			getline(stream, token, ',');
			theme = token;
			getline(stream, token, ',');
			name = token;
			getline(stream, token, ',');
			minifigs = stoi(token);
			getline(stream, token, ',');
			pieces = stoi(token);
			getline(stream, token, ',');
			price = stod(token);

			// Create Lego from csv data
			Lego tempLego(number, theme, name, minifigs, pieces, price);
			tempLegoList.push_back(tempLego);
		}
	}
	// return Lego vector
	return tempLegoList;
}

int main()
{
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	vector<Lego> legoList; // This vector holds the Lego's created from the csv

	if (option == 1) {
		legoList = ReadDataFromFile("lego1.csv");
	}
	
	else if (option == 2) {
		legoList = ReadDataFromFile("lego2.csv");
	}

	else if (option == 3) {
		legoList = ReadDataFromFile("lego3.csv");
	}

	else if (option == 4) {
	/*****************************************************************
	/ CITATION FOR Concatenating multiple vectors:
	/
	/ Article: Concatenate two vectors in C++
	/ Site: Techie Delight
	/ Aurhor: Unknown
	/ URL: https://www.techiedelight.com/concatenate-two-vectors-cpp/
	****************************************************************/
		vector<Lego> legoList1 = ReadDataFromFile("lego1.csv");
		vector<Lego> legoList2 = ReadDataFromFile("lego2.csv");
		vector<Lego> legoList3 = ReadDataFromFile("lego3.csv");
		legoList = legoList1;
		legoList.insert(legoList.end(), legoList2.begin(), legoList2.end());
		legoList.insert(legoList.end(), legoList3.begin(), legoList3.end());
	}

	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;
	cout << endl;

	cout << "Total number of sets: " << legoList.size() << endl;
	cout << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	unsigned int i;

	// Most expensive
	if (choice == 1) {
		int tracker = -1;
		double mostExpensive = 0;

		for (i = 0; i < legoList.size(); ++i) {
			if (legoList.at(i).getPrice() > mostExpensive) {
				mostExpensive = legoList.at(i).getPrice();
				tracker = i;
			}
		}
		cout << "The most expensive set is:" << endl;
		legoList.at(tracker).printLego();
	}

	// Largest Piece Count
	else if (choice == 2) {
		int tracker = -1;
		int pieceCount = 0;

		for (i = 0; i < legoList.size(); ++i) {
			if (legoList.at(i).getPieces() > pieceCount) {
				pieceCount = legoList.at(i).getPieces();
				tracker = i;
			}
		}
		cout << "The set with the highest parts count:" << endl;
		legoList.at(tracker).printLego();
	}

	// Search For Name
	else if (choice == 3) {
		vector<int> legoNames;
		string searchName;
		getline(cin, searchName);
		for (i = 0; i < legoList.size(); ++i) {
			if (legoList.at(i).getName().find(searchName) != string::npos) {
				legoNames.push_back(i);
			}
		}
		if (legoNames.size() == 0) {
			cout << "No sets found matching that search term" << endl;
		}
		else {
			cout << "Sets matching \"" << searchName << "\":" << endl;
			for (i = 0; i < legoNames.size(); ++i) {
				int j = legoNames.at(i);
				legoList.at(j).printLegoShort();
			}
		}
	}

	// Search Themes
	else if (choice == 4) {
		vector<int> legoThemes;
		string searchTheme;
		getline(cin, searchTheme);

		for (i = 0; i < legoList.size(); ++i) {
			if (legoList.at(i).getTheme().find(searchTheme) != string::npos) {
				legoThemes.push_back(i);
			}
		}
		if (legoThemes.size() == 0) {
			cout << "No sets found matching that search term" << endl;
		}
		else {
			cout << "Sets matching \"" << searchTheme << "\":" << endl;
			for (i = 0; i < legoThemes.size(); ++i) {
				int j = legoThemes.at(i);
				legoList.at(j).printLegoShort();
			}
		}
	}

	// Part Count Avg
	else if (choice == 5) {
		int average;
		int pTotal = 0;
		int pCount = 0;

		for (i = 0; i < legoList.size(); ++i) {
			pTotal += legoList.at(i).getPieces();
			pCount++;
		}
		average = pTotal / pCount;
		cout << "Average part count for " << legoList.size() << " sets: "<< average << endl;
	}

	// Price Avg, Min, Max
	else if (choice == 6) {
		double average = 0;
		double pTotal = 0;
		int pCount = 0;
		double minimum = 0;
		int minID = -1;
		double maximum = 0;
		int maxID = -1;

		for (i = 0; i < legoList.size(); ++i) {
			double price = legoList.at(i).getPrice();
			if (i == 0) {
				maximum = price;
				minimum = price;
			}
			else {
				if (price > maximum) {
					maximum = price;
					maxID = i;
				}
				if (price < minimum) {
					minimum = price;
					minID = i;
				}
			}
			pTotal += price;
			pCount++;
		}
		average = pTotal / pCount;
		cout << "Average price for " << legoList.size() << " sets: $" << average << endl;
		cout << "\nLeast expensive set: " << endl;
		legoList.at(minID).printLego();
		cout << "\nMost expensive set: " << endl;
		legoList.at(maxID).printLego();
	}

	// Minfig Info
	else if (choice == 7) {
		int mTotal = 0;
		int mCount = 0;
		int average = 0;
		int max = 0;
		int tracker = -1;

		for (i = 0; i < legoList.size(); ++i) {
			int minis = legoList.at(i).getMinifigs();
			if (i == 0) {
				max = minis;
				tracker = i;
			}
			else {
				if (minis > max) {
					max = minis;
					tracker = i;
				}
			}
			mTotal += minis;
			mCount++;
		}
		average = mTotal / mCount;
		cout << "Average number of minifigures: " << average << endl;
		cout << "Set with the most minifigures:" << endl;
		legoList.at(tracker).printLego();
	}

	// If You Bought One of Each
	else if (choice == 8) {
		double cost = 0;
		int pieces = 0;
		int minis = 0;
		for (i = 0; i < legoList.size(); ++i) {
			cost += legoList.at(i).getPrice();
			pieces += legoList.at(i).getPieces();
			minis += legoList.at(i).getMinifigs();
		}
		cout << "If you bought one of everything..." << endl;
		cout << "It would cost: $" << cost << endl;
		cout << "You would have " << pieces << " pieces in your collection" << endl;
		cout << "You would have an army of " << minis << " minifigures!" << endl;
	}
	cout << endl;
	return 0;
}
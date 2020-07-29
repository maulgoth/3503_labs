// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <sstream>
#include "Color.h"
using namespace std;

void ReadFile(const char* filename,  map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	map<string, Color> colors;
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	}
	else if (choice == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}

	}
	
	// Secondary menu
	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1)
		PrintColors(colors);
	else if (choice == 2)
		SearchForColor(colors);
	return 0;
}

void ReadFile(const char* filename, map<string, Color>& colors)
{
    string name;
    int value;
   // TODO: Read the file, create and store some Color objects

   ifstream file(filename);
   string line;
   while (getline(file, line)) {
       stringstream stream(line);
       string item;
       while (getline(stream, item, ' ')) {
           name = item;
           getline(stream, item, ' ');
           value = stoi(item);
           Color c(name, value);
           colors.emplace(name, c);
       }
   }
}
void PrintColors(const map<string, Color>& colors)
{
    int count = 0;
   // TODO: iterate through all entries in the map and print each color, one at a time
   // Print out the color count afterward
    map<string, Color>::const_iterator iter;
    for (iter = colors.begin(); iter != colors.end(); iter++) {
        PrintColor(iter->second);
        count++;
    }
    cout << "Number of colors: " << count << endl;
}
void PrintColor(const Color& color)
{
	cout << left << setw(20) << color.GetName();
	cout << right << setw(10) << color.GetHexValue();
	cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors)
{
    string colorSearch;
    cin >> colorSearch;
	// TODO: Get some input, check if that key exists, then print out the color (or an error message)
    if (colors.find(colorSearch) == colors.end())
        cout << colorSearch <<" not found!" << endl;
    else
        PrintColor(colors.find(colorSearch)->second);
}

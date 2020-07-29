// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using std::string;
using std::map;
using std::vector;

class Color
{
    // Map of hex chars > 9
    map<int, char> numbers = {
        {10, 'A'},
        {11, 'B'},
        {12, 'C'},
        {13, 'D'},
        {14, 'E'},
        {15, 'F'}
    };
    string name;
    int value;
    vector<int> hexy;
public:
    Color(string _name, int _value);
    string GetName() const;
    string GetHexValue() const;
    int GetR() const;
    int GetG() const;
    int GetB() const;
    int HexToDec(int rgb) const;
};
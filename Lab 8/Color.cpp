// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

#include "Color.h"

Color::Color(string _name, int _value) {
    name = _name;
    value = _value;
}

string Color::GetName() const {
    return name;
}

string Color::GetHexValue() const {
    string hexValue;
    vector<int> hexVector;
    int rem;
    int quotient = value;
    while (quotient != 0) {
        rem = quotient % 16;
        quotient = quotient / 16;
        hexVector.push_back(rem);
    }
    for (unsigned int i = 0; i < hexVector.size(); i++) {
        if (hexVector.at(i) > 9) {
            char c = numbers.find(hexVector.at(i))->second;
            hexValue = c + hexValue;
        }
        else
            hexValue = std::to_string(hexVector.at(i)) + hexValue;
    }
    if (hexValue.length() < 6) { // Add 0's to beginning
        unsigned int x = 6 - hexValue.length();
        for (unsigned int i = 0; i < x; i++)
            hexValue = std::to_string(0) + hexValue;
    }

    hexValue = "0x" + hexValue;
    return hexValue;
}

int Color::GetR() const {
    return HexToDec(0);
}

int Color::GetG() const {
    return HexToDec(1);
}

int Color::GetB() const {
    return HexToDec(2);
}

int Color::HexToDec(int rgb) const {
    int first, second;
    switch (rgb) {
    case 0: // Red
        first = 2;
        second = 3;
        break;
    case 1: // Green
        first = 4;
        second = 5;
        break;
    case 2: // Blue
        first = 6;
        second = 7;
        break;
    }

    char colorArray[2];
    int colorInts[2];
    colorArray[0] = GetHexValue().at(first);
    colorArray[1] = GetHexValue().at(second);

    for (int i = 0; i < 2; i++) {
        bool changed = false;
        map<int, char>::const_iterator iter;
        for (iter = numbers.begin(); iter != numbers.end(); iter++) {
            if (iter->second == colorArray[i]) {
                colorInts[i] = iter->first;
                changed = true;
            }
        }
        if (!changed)
            colorInts[i] = colorArray[i] - 48; // subtract 48 char -> int
    }

    int C = (colorInts[0] * 16) + colorInts[1];
    return C;
}
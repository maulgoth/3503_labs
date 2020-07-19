#include <iostream>
#include <string>
#include "Shapes.h"
using namespace std;

const float PI = 3.14159f; // Create an actual variable with PI as its value

// SHAPE ------------------------------------------------------- //

void Shape::Scale(float scaleFactor) {

};

void Shape::Display() const {

};

// SHAPE 2D ------------------------------------------------------- //

float Shape2D::Area() const {

};

void Shape2D::ShowArea() const {

};

string Shape2D::GetName2D() const {

};

bool Shape2D::operator>(const Shape2D &rhs) const {

};

bool Shape2D::operator<(const Shape2D &rhs) const {

};

bool Shape2D::operator==(const Shape2D &rhs) const {

};

// SHAPE 3D ------------------------------------------------------- //


float Shape3D::Volume() const {

};

void Shape3D::ShowVolume() const {

};

string Shape3D::GetName3d() const {

};

bool Shape3D::operator>(const Shape3D &rhs) const {

};

bool Shape3D::operator<(const Shape3D &rhs) const {

};

bool Shape3D::operator==(const Shape3D &rhs) const {

};

// SQUARE ------------------------------------------------------- //

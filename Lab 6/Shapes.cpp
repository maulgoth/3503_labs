#include <iostream>
#include <string>
#include "Shapes.h"
using namespace std;

const float PI = 3.14159f; // Create an actual variable with PI as its value

// MAKE SURRRRRRRRRRRRRRE TO ROUND OFF FLOATS AT 3 DECIMAL PLACES!
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// LOOK ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

// SHAPE -----------------------------------------------------------//
Shape::~Shape() {}

// SHAPE 2D ------------------------------------------------------- //
void Shape2D::ShowArea() const {
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const {
    if (Area() > rhs.Area())
        return true;
    return false;
}

bool Shape2D::operator<(const Shape2D &rhs) const {
    if (Area() < rhs.Area())
        return true;
    return false;
}

bool Shape2D::operator==(const Shape2D &rhs) const {
    if (Area() == rhs.Area())
        return true;
    return false;
}

Shape2D::~Shape2D() {}

// SHAPE 3D ------------------------------------------------------- //
void Shape3D::ShowVolume() const {
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D &rhs) const {
    if (Volume() > rhs.Volume())
        return true;
    return false;
}

bool Shape3D::operator<(const Shape3D &rhs) const {
    if (Volume() < rhs.Volume())
        return true;
    return false;
}

bool Shape3D::operator==(const Shape3D &rhs) const {
    if (Volume() == rhs.Volume())
        return true;
    return false;
}

Shape3D::~Shape3D() {}

// SQUARE ------------------------------------------------------- //
Square::Square() {
    side = 0;
}

Square::Square(float _side) {
    side = _side;
}

void Square::Scale(float scaleFactor) {
    side *= scaleFactor;
}

void Square::Display() const {
    cout << "The area of the Square is : " << Area() << endl;
    cout << "Length of a side: " << side << endl;
}

float Square::Area() const {
    // area = side^2
    return side * side;
}

string Square::GetName2D() const {
    return "Square";
}

Square::~Square() {}

// TRIANGLE ------------------------------------------------------- //
Triangle::Triangle() {
    base = 0;
    height = 0;
}

Triangle::Triangle(float _base, float _height) {
    base = _base;
    height = _height;
}

void Triangle::Scale(float scaleFactor) {
    base *= scaleFactor;
    height *= scaleFactor;
}

void Triangle::Display() const {
    cout << "The area of the Triangle is : " << Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}

float Triangle::Area() const {
    // area = 0.5 * (base * height)
    return 0.5 * (base * height);
}

string Triangle::GetName2D() const {
    return "Triangle";
}

float Triangle::GetBase() const {
    return base;
}

float Triangle::GetHeight() const {
    return height;
}

Triangle::~Triangle() {}

// CIRCLE ------------------------------------------------------- //
Circle::Circle() {
    radius = 0;
}

Circle::Circle(float _radius) {
    radius = _radius;
}

void Circle::Scale(float scaleFactor) {
    radius *= scaleFactor;
}

void Circle::Display() const {
    cout << "The area of the Circle is : " << Area() << endl;
    cout << "Radius: " << radius << endl;
}

float Circle::Area() const {
    // area = PI * (radius * radius)
    return PI * (radius * radius);
}

string Circle::GetName2D() const {
    return "Circle";
}

float Circle::GetRadius() const {
    return radius;
}

Circle::~Circle() {}

// TRIANGULAR PYRAMID ------------------------------------------- //
TriangularPyramid::TriangularPyramid() {
    pyrHeight = 0;
}

TriangularPyramid::TriangularPyramid(float _pyrHeight, float _triBase, float _tri_Height) : Triangle(_triBase, _tri_Height) {
    pyrHeight = _pyrHeight;
}

void TriangularPyramid::Scale(float scaleFactor) {
    pyrHeight *= scaleFactor;
    Triangle::Scale(scaleFactor);
}

void TriangularPyramid::Display() const {
    cout << "The volume of the Triangular Pyramid is : " << TriangularPyramid::Volume() << endl;
    cout << "The height is: " << pyrHeight << endl;
    cout << "The area of the Triangle is : " << Triangle::Area() << endl;
    cout << "Base: " << Triangle::GetBase() << endl;
    cout << "Height: " << Triangle::GetHeight() << endl;
}

float TriangularPyramid::Volume() const {
    // volume = 1/3 * area * height
    return (1.0/3.0) * (Triangle::Area() * pyrHeight);
}

string TriangularPyramid::GetName3D() const {
    return "Triangular Pyramid";
}

TriangularPyramid::~TriangularPyramid() {}

// CYLINDER ----------------------------------------------------- //
Cylinder::Cylinder() {
    height = 0;
}

Cylinder::Cylinder(float _height, float _circRadius) : Circle(_circRadius) {
    height = _height;
}

void Cylinder::Scale(float scaleFactor) {
    height *= scaleFactor;
    Circle::Scale(scaleFactor);
}

void Cylinder::Display() const {
    cout << "The volume of the Cylinder is : " << Cylinder::Volume() << endl;
    cout << "The height is: " << height << endl;
    cout << "The area of the Circle is : " << Circle::Area() << endl;
    cout << "Radius: " << Circle::GetRadius() << endl;
}

float Cylinder::Volume() const {
    // volume = pi * (radius * radius) * height
    return PI * (Circle::GetRadius() * Circle::GetRadius()) * height; 
}

string Cylinder::GetName3D() const {
    return "Cylinder";
}

Cylinder::~Cylinder() {}

// SPHERE ------------------------------------------------------- //
Sphere::Sphere() {}

Sphere::Sphere(float _sphereRadius) : Circle(_sphereRadius) {
}

void Sphere::Scale(float scaleFactor) {
    Circle::Scale(scaleFactor);
}

void Sphere::Display() const {
    cout << "The volume of the Sphere is : " << Sphere::Volume() << endl;
    cout << "The area of the Circle is : " << Circle::Area() << endl;
    cout << "Radius: " << Circle::GetRadius() << endl;
}

float Sphere::Volume() const {
    // volume = 4/3 * pi * (radius * radius * radius)
    return (4.0/3.0) * PI * (Circle::GetRadius() * Circle::GetRadius() * Circle::GetRadius()); 
}

string Sphere::GetName3D() const {
    return "Sphere";
}

Sphere::~Sphere() {}
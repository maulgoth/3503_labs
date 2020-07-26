// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Shape
{
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape();
};

class Shape2D : virtual public Shape
{
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
    ~Shape2D();
};

class Shape3D : virtual public Shape
{
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
    ~Shape3D();
};

class Square : public Shape2D
{
public:
    Square();
    Square(float _side);
    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
    ~Square();

private:
    float side;
};

class Triangle : public Shape2D
{
public:
    Triangle();
    Triangle(float _base, float _height);
    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
    float GetBase() const;
    float GetHeight() const;
    ~Triangle();

private:
    float base;
    float height;
};

class Circle : public Shape2D
{
public:
    Circle();
    Circle(float _radius);
    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
    float GetRadius() const;
    ~Circle();

private:
    float radius;
};

class TriangularPyramid : public Shape3D, private Triangle
{
public:
    TriangularPyramid();
    TriangularPyramid(float _pyrHeight, float _triBase, float _tri_Height);
    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
    ~TriangularPyramid();

private:
    float pyrHeight;
};

class Cylinder : public Shape3D, private Circle
{
public:
    Cylinder();
    Cylinder(float _height, float _circRadius);
    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
    ~Cylinder();

private:
    float height;
};

class Sphere : public Shape3D, private Circle
{
public:
    Sphere();
    Sphere(float _sphereRadius);
    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
    ~Sphere();
};
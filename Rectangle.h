#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Rectangle
{
protected:
	double sideA;
	double sideB;

public:
	Rectangle();
	Rectangle(double a, double b);

	void setSides(double a, double b);
	double getSideA() const;
	double getSideB() const;

	double computeArea() const;
	double computePerimeter() const;
	double computeDiagonal() const;

	void print() const;
	void print(string title) const;

	friend ostream& operator<<(ostream& out, const Rectangle& r);
	friend istream& operator>>(istream& in, Rectangle& r);
};

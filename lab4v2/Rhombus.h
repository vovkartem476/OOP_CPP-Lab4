#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Rhombus
{
protected:
	double d1;
	double d2;

public:
	Rhombus();
	Rhombus(double d1, double d2);

	void setDiagonals(double d1, double d2);
	double getD1() const;
	double getD2() const;

	double computeSide() const;
	double computeArea() const;
	double computePerimeter() const;

	void print() const;
	void print(string title) const;

	friend ostream& operator<<(ostream& out, const Rhombus& r);
	friend istream& operator>>(istream& in, Rhombus& r);
};

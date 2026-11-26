#pragma once
#include <iostream>
#include <string>

using namespace std;

class Circle
{
protected:
	double radius;

public:
	Circle();
	Circle(double radius);

	void setRadius(double value);
	double getRadius() const;

	double computeArea() const;
	double computeCircumference() const;

	void print() const;
	void print(string title) const;

	friend ostream& operator<<(ostream& out, const Circle& c);
	friend istream& operator>>(istream& in, Circle& c);
};

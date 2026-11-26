#include "Circle.h"
#include <cmath>
#include <stdexcept>

const double PI = acos(-1.0);

Circle::Circle() {
	radius = 0;
}

Circle::Circle(double radius) {
	setRadius(radius);
}

void Circle::setRadius(double value) {
	if (value <= 0)
		throw invalid_argument("Помилка: радіус має бути більшим за 0!");
	radius = value;
}

double Circle::getRadius() const {
	if (radius <= 0)
		throw logic_error("Помилка: радіус не задано!");
	return radius;
}

double Circle::computeArea() const {
	return PI * radius * radius;
}

double Circle::computeCircumference() const {
	return 2 * PI * radius;
}

void Circle::print() const {
	cout << "Радіус: " << radius << endl;
	cout << "Площа кола: " << computeArea() << endl;
	cout << "Довжина кола: " << computeCircumference() << endl;
}

void Circle::print(string title) const {
	cout << title << endl;
	print();
}

ostream& operator<<(ostream& out, const Circle& c) {
	out << "Радіус: " << c.radius
	    << ", площа кола: " << c.computeArea()
	    << ", довжина кола: " << c.computeCircumference();
	return out;
}

istream& operator>>(istream& in, Circle& c) {
	double r;
	if (in >> r)
		c.setRadius(r);
	return in;
}

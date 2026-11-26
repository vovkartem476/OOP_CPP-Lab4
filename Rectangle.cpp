#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle() {
	sideA = 0;
	sideB = 0;
}

Rectangle::Rectangle(double a, double b) {
	setSides(a, b);
}

void Rectangle::setSides(double a, double b) {
	if (a <= 0 || b <= 0)
		throw invalid_argument("Помилка: сторони прямокутника мають бути більшими за 0!");
	sideA = a;
	sideB = b;
}

double Rectangle::getSideA() const {
	if (sideA <= 0)
		throw logic_error("Помилка: прямокутник ще не заданий!");
	return sideA;
}

double Rectangle::getSideB() const {
	if (sideB <= 0)
		throw logic_error("Помилка: прямокутник ще не заданий!");
	return sideB;
}

double Rectangle::computeArea() const {
	return getSideA() * getSideB();
}

double Rectangle::computePerimeter() const {
	return 2 * (getSideA() + getSideB());
}

double Rectangle::computeDiagonal() const {
	return sqrt(getSideA() * getSideA() + getSideB() * getSideB());
}

void Rectangle::print() const {
	cout << "Сторона A: " << getSideA() << endl;
	cout << "Сторона B: " << getSideB() << endl;
	cout << "Площа прямокутника: " << computeArea() << endl;
	cout << "Периметр прямокутника: " << computePerimeter() << endl;
	cout << "Діагональ: " << computeDiagonal() << endl;
}

void Rectangle::print(string title) const {
	cout << title << endl;
	print();
}

ostream& operator<<(ostream& out, const Rectangle& r) {
	out << "Сторона A: " << r.getSideA()
	    << ", сторона B: " << r.getSideB()
	    << ", площа: " << r.computeArea()
	    << ", периметр: " << r.computePerimeter()
	    << ", діагональ: " << r.computeDiagonal();
	return out;
}

istream& operator>>(istream& in, Rectangle& r) {
	double a, b;
	if (in >> a >> b)
		r.setSides(a, b);
	return in;
}

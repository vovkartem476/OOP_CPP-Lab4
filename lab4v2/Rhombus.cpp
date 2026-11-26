#include "Rhombus.h"
#include <cmath>

Rhombus::Rhombus() {
	d1 = 0;
	d2 = 0;
}

Rhombus::Rhombus(double d1, double d2) {
	setDiagonals(d1, d2);
}

void Rhombus::setDiagonals(double d1, double d2) {
	if (d1 <= 0 || d2 <= 0)
		throw invalid_argument("Помилка: діагоналі мають бути більшими за 0!");
	this->d1 = d1;
	this->d2 = d2;
}

double Rhombus::getD1() const {
	if (d1 <= 0)
		throw logic_error("Помилка: ромб ще не заданий!");
	return d1;
}

double Rhombus::getD2() const {
	if (d2 <= 0)
		throw logic_error("Помилка: ромб ще не заданий!");
	return d2;
}

double Rhombus::computeSide() const {
	return sqrt(d1*d1 + d2*d2)/2;
}

double Rhombus::computeArea() const {
	return d1 * d2 / 2.0;
}

double Rhombus::computePerimeter() const {
	return 4.0 * computeSide();
}

void Rhombus::print() const {
	cout << "Діагональ d1: " << getD1() << endl;
	cout << "Діагональ d2: " << getD2() << endl;
	cout << "Сторона: " << computeSide() << endl;
	cout << "Площа ромба: " << computeArea() << endl;
	cout << "Периметр ромба: " << computePerimeter() << endl;
}

void Rhombus::print(string title) const {
	cout << title << endl;
	print();
}

ostream& operator<<(ostream& out, const Rhombus& r) {
	out << "d1: " << r.getD1()
	    << ", d2: " << r.getD2()
	    << ", сторона: " << r.computeSide()
	    << ", площа: " << r.computeArea()
	    << ", периметр: " << r.computePerimeter();
	return out;
}

istream& operator>>(istream& in, Rhombus& r) {
	double d1, d2;
	if (in >> d1 >> d2)
		r.setDiagonals(d1, d2);
	return in;
}

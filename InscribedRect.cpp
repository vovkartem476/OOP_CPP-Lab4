#include "InscribedRect.h"
#include <cmath>

InscribedRect::InscribedRect(double a, double b)
	: Circle(sqrt(a * a + b * b) / 2.0), Rectangle(a, b)
{
}

void InscribedRect::print() const {
	cout << "Прямокутник, вписаний у коло" << endl;

	cout << "\n[Коло]" << endl;
	Circle::print();

	cout << "\n[Прямокутник]" << endl;
	Rectangle::print();
}

void InscribedRect::print(string title) const {
	cout << title << endl;
	print();
}

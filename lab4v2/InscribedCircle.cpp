#include "InscribedCircle.h"
#include <cmath>

static double inscribedRadius(double d1, double d2) {
	double side = sqrt((d1/2)*(d1/2) + (d2/2)*(d2/2));
	return (d1 * d2) / (4.0 * side);
}

InscribedCircle::InscribedCircle(double d1, double d2)
	: Circle(inscribedRadius(d1, d2)), Rhombus(d1, d2)
{
}

void InscribedCircle::print() const {
	cout << "Коло, вписане в ромб" << endl;

	cout << "\n[Ромб]" << endl;
	Rhombus::print();

	cout << "\n[Коло]" << endl;
	Circle::print();
}

void InscribedCircle::print(string title) const {
	cout << title << endl;
	print();
}

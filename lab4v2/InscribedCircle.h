#pragma once
#include "Circle.h"
#include "Rhombus.h"

class InscribedCircle : public Circle, public Rhombus
{
public:
	InscribedCircle(double d1, double d2);

	void print() const;
	void print(string title) const;
};

#pragma once
#include "Circle.h"
#include "Rectangle.h"

class InscribedRect : public Circle, public Rectangle
{
public:
	InscribedRect(double a, double b);

	void print() const;
	void print(string title) const;
};

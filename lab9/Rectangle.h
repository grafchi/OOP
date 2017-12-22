#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Figure.h"

class Rectangle : public Figure{
public:
	Rectangle();
	Rectangle(std::istream& is);
	Rectangle(double a,double b);
	double Area() override;

	friend std::ostream& operator <<(std::ostream & os, const Rectangle & obj);
    friend std::istream& operator >>(std::istream & is, Rectangle & obj);
    virtual ~Rectangle();
private:
	double side_a;
	double side_b;
};

#endif



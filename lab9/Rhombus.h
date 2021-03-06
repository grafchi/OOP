#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>
#include "Figure.h"
class Rhombus : public Figure{
public:
	Rhombus();
	Rhombus(double a, double b);
	Rhombus(std::istream& is);
	double Area() override;
    friend std::ostream& operator <<(std::ostream & os, const Rhombus & obj);
    friend std::istream& operator >>(std::istream & is, Rhombus & obj);
    virtual ~Rhombus();
private:
	double side;
	double height;
};

#endif



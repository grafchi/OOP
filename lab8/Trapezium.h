#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <iostream>
#include "Figure.h"
class Trapezium : public Figure{
public:
	Trapezium();
	Trapezium(std::istream& is);
	double Area() override;
    friend std::ostream& operator <<(std::ostream & os, const Trapezium & obj);
    friend std::istream& operator >>(std::istream & is, Trapezium & obj);
    virtual ~Trapezium();
private:
	double side_a;
	double side_b;
	double height;
};

#endif


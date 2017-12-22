#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle{
public:
    bool err=false;
	Rectangle();
	Rectangle(std::istream & is);

	double Square();

	Rectangle& operator =(const Rectangle & right);
    bool operator ==(const Rectangle & right) const;
    friend std::ostream& operator <<(std::ostream & os, const Rectangle & obj);
    friend std::istream& operator >>(std::istream & is, Rectangle & obj);

    virtual ~Rectangle();
private:
	double side_a;
	double side_b;
};

#endif


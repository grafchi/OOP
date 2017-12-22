#ifndef CONT.H
#define CONT.H

#include <memory>
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include "ContItem.h"

const int size = 10;

class Cont{
public:
    Cont();

    void push(std::shared_ptr<Rectangle> &&rectangle, int index);
    void push(std::shared_ptr<Rhombus> &&rhombus, int index);
    void push(std::shared_ptr<Trapezium> &&trapezium, int index);

    bool IsRectangle(int index);
	bool IsRhombus(int index);
	bool IsTrapezium(int index);

	std::shared_ptr<Rectangle> GetRectangle(int index);
	std::shared_ptr<Rhombus> GetRhombus(int index);
	std::shared_ptr<Trapezium> GetTrapezium(int index);

    void removeIt(int index);
    friend std::ostream& operator <<(std::ostream & os,const Cont & cont);
    virtual ~Cont();
private:
    ContItem a[size];
};
#endif


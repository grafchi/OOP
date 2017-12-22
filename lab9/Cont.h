#ifndef CONT.H
#define CONT.H

#include <memory>
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include "ContItem.h"
#include "Iterator.cpp"

const int size = 10;

template <class T1, class T2, class T3>
class Cont{
public:
    Cont(int size);

    void push(std::shared_ptr<T1> && t, int index);
    void push(std::shared_ptr<T2> && t, int index);
    void push(std::shared_ptr<T3> && t, int index);

    bool IsT1(int index);
	bool IsT2(int index);
	bool IsT3(int index);

	std::shared_ptr<T1> GetT1(int index);
	std::shared_ptr<T2> GetT2(int index);
	std::shared_ptr<T3> GetT3(int index);

    void removeIt(int index);
    void removeIt_area(double area_);

    Iterator<T1, T2, T3> begin();
	Iterator<T1, T2, T3> end();

    template <class A1, class A2, class A3> friend std::ostream& operator <<(std::ostream & os,const Cont<A1, A2, A3> & cont);
    virtual ~Cont();
private:
    ContItem<T1, T2, T3> *a;
    int size_;
    Iterator<T1, T2, T3> first;
	Iterator<T1, T2, T3> last;
};

#endif


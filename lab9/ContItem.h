#ifndef CONTITEM_H
#define CONTITEM_H

#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include "Allocator.h"
#include <memory>
#include <iostream>


template <class T1, class T2, class T3>
class ContItem{
public:
    ContItem();
    ContItem(int index);
	ContItem(std::shared_ptr<T1> &t, int index);
	ContItem(std::shared_ptr<T2> &t, int index);
	ContItem(std::shared_ptr<T3> &t, int index);

	bool IsT1() const;
	bool IsT2() const;
	bool IsT3() const;

	std::shared_ptr<T1> GetT1();
	std::shared_ptr<T2> GetT2();
	std::shared_ptr<T3> GetT3();

	void SetIndex(int index);
	int GetIndex();
	double Area_();

    void *operator new(size_t size);
    void operator delete(void *ptr);

    template <class A1, class A2, class A3> friend std::ostream& operator<< (std::ostream & os, const ContItem<A1, A2, A3> & item);
    virtual ~ContItem();
private:
    std::shared_ptr<T1> t1;
	std::shared_ptr<T2> t2;
	std::shared_ptr<T3> t3;
	int index_;

	static Allocator arritem_allocator;
};

#endif



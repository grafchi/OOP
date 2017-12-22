#ifndef CONTITEM_H
#define CONTITEM_H

#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include "Allocator.h"
#include "BTree.h"
#include <memory>
#include <iostream>

template <class T1, class T2, class T3> class Cont;
template <class T1, class T2, class T3>
class ContItem{
public:
    ContItem();
    ContItem(std::shared_ptr<BTree<T1,T2,T3>> & t, int index);
	/*ContItem(std::shared_ptr<T1> &t, int index);
	ContItem(std::shared_ptr<T2> &t, int index);
	ContItem(std::shared_ptr<T3> &t, int index);

	bool IsT1() const;
	bool IsT2() const;
	bool IsT3() const;

	std::shared_ptr<T1> GetT1();
	std::shared_ptr<T2> GetT2();
	std::shared_ptr<T3> GetT3(); */
	void SetIndex(int index);
	int GetIndex(int index);

    template <class A1, class A2, class A3> friend std::ostream& operator<< (std::ostream & os, const ContItem<A1, A2, A3> & item);
    friend Cont<T1,T2,T3>;
    virtual ~ContItem();
private:
    std::shared_ptr<BTree<T1,T2,T3>> t;
    int index_;
};

#endif



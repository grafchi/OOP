#ifndef BTREEITEM_H
#define BTREEITEM_H

#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include "Allocator.h"
#include <memory>

template <class T1, class T2, class T3> class BTree;
template <class T1, class T2, class T3> class Cont;
template <class T1, class T2, class T3>
class BTreeItem{
public:
    BTreeItem();
	BTreeItem(std::shared_ptr<T1> & t1);
	BTreeItem(std::shared_ptr<T2> & t2);
	BTreeItem(std::shared_ptr<T3> & t3);

	bool IsT1() const;
	bool IsT2() const;
	bool IsT3() const;

	std::shared_ptr<T1> GetT1();
	std::shared_ptr<T2> GetT2();
	std::shared_ptr<T3> GetT3();
	double Area();

    void *operator new(size_t size);
    void operator delete(void *ptr);

    template <class A1, class A2, class A3> friend std::ostream& operator<< (std::ostream & os, const BTreeItem<A1, A2, A3> & item);
    friend BTree<T1,T2,T3>;
    friend Cont<T1,T2,T3>;
	virtual ~BTreeItem();
private:
	std::shared_ptr<BTreeItem<T1,T2,T3>> leftT;
	std::shared_ptr<BTreeItem<T1,T2,T3>> rightT;
    std::shared_ptr<T1> t1;
	std::shared_ptr<T2> t2;
	std::shared_ptr<T3> t3;

	static Allocator arritem_allocator;
};

#endif

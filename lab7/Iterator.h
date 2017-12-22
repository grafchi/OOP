#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>
#include "ContItem.cpp"

template<class T1, class T2, class T3>
class Iterator
{
public:

	Iterator();
	Iterator(ContItem<T1, T2, T3>* p);

	ContItem<T1, T2, T3>* operator *();

	bool operator==(Iterator i);
	bool operator != (Iterator i);

	void operator ++ ();

private:
	ContItem<T1, T2, T3> * el;
};

#endif

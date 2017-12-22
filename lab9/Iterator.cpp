#include "Iterator.h"

template<class T1, class T2, class T3>
Iterator<T1, T2, T3>::Iterator()
{
	el = nullptr;
}

template<class T1, class T2, class T3>
Iterator<T1, T2, T3>::Iterator(ContItem<T1, T2, T3>* p)
{
	el = p;
}

template<class T1, class T2, class T3>
ContItem<T1, T2, T3>* Iterator<T1, T2, T3>::operator * ()
{
	return el;
}

template<class T1, class T2, class T3>
bool Iterator<T1, T2, T3>::operator ==(Iterator i)
{
	return el == i.el;
}

template<class T1, class T2, class T3>
bool Iterator<T1, T2, T3>::operator !=(Iterator i)
{
	return !(*this == i);
}

template<class T1, class T2, class T3>
void Iterator<T1, T2, T3>::operator ++ ()
{
	el++;
}

#include "ContItem.h"

template <class T1, class T2, class T3> ContItem<T1, T2, T3>::ContItem() : t(nullptr) {}
template <class T1, class T2, class T3> ContItem<T1, T2, T3>::ContItem(std::shared_ptr<BTree<T1,T2,T3>> & t, int index) : t(t), index_(index) {}
/*template <class T1, class T2, class T3> ContItem<T1, T2, T3>::ContItem(std::shared_ptr<T1> &t, int index) : t1(t), t2(nullptr), t3(nullptr), index_(index) {}
template <class T1, class T2, class T3> ContItem<T1, T2, T3>::ContItem(std::shared_ptr<T2> &t, int index) : t1(nullptr), t2(t), t3(nullptr), index_(index) {}
template <class T1, class T2, class T3> ContItem<T1, T2, T3>::ContItem(std::shared_ptr<T3> &t, int index) : t1(nullptr), t2(nullptr), t3(t), index_(index) {}
*/
/*template <class T1, class T2, class T3> bool ContItem<T1, T2, T3>::IsT1() const
{
	if (t1 != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool ContItem<T1, T2, T3>::IsT2() const
{
	if (t2 != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool ContItem<T1, T2, T3>::IsT3() const
{
	if (t3 != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> std::shared_ptr<T1> ContItem<T1, T2, T3>::GetT1()
{
	return this->t1;
}
template <class T1, class T2, class T3> std::shared_ptr<T2> ContItem<T1, T2, T3>::GetT2()
{
	return this->t2;
}
template <class T1, class T2, class T3> std::shared_ptr<T3> ContItem<T1, T2, T3>::GetT3()
{
	return this->t3;
} */
template <class T1, class T2, class T3> void ContItem<T1, T2, T3>::SetIndex(int index)
{
	index_ = index;
	return;
}
template <class T1, class T2, class T3> int ContItem<T1, T2, T3>::GetIndex(int index)
{
	return index_;
}
template <class A1, class A2, class A3> std::ostream& operator << (std::ostream &os, const ContItem<A1, A2, A3> &item)
{
	if (item.t)
		os << *item.t << std::endl;
	else
		os << "�����" << std::endl;
	return os;
}
template <class T1, class T2, class T3> ContItem<T1, T2, T3>::~ContItem() {
}
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
template class ContItem<Rectangle, Rhombus, Trapezium>;
template std::ostream& operator <<(std::ostream & os,const ContItem<Rectangle, Rhombus, Trapezium> & item);

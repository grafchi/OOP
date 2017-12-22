#include "BTreeItem.h"

template <class T1, class T2, class T3> BTreeItem<T1,T2,T3>::BTreeItem() : leftT(nullptr), rightT(nullptr), t1(nullptr), t2(nullptr), t3(nullptr) {}
template <class T1, class T2, class T3> BTreeItem<T1,T2,T3>::BTreeItem(std::shared_ptr<T1> & t1) : leftT(nullptr), rightT(nullptr), t1(t1), t2(nullptr), t3(nullptr) {}
template <class T1, class T2, class T3> BTreeItem<T1,T2,T3>::BTreeItem(std::shared_ptr<T2> & t2) : leftT(nullptr), rightT(nullptr), t1(nullptr), t2(t2), t3(nullptr) {}
template <class T1, class T2, class T3> BTreeItem<T1,T2,T3>::BTreeItem(std::shared_ptr<T3> & t3) : leftT(nullptr), rightT(nullptr), t1(nullptr), t2(nullptr), t3(t3) {}
template <class T1, class T2, class T3> Allocator BTreeItem<T1, T2, T3>::arritem_allocator(sizeof(BTreeItem<T1, T2, T3>), 5);
template <class T1, class T2, class T3> bool BTreeItem<T1,T2,T3>::IsT1() const{
    if (t1 != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool BTreeItem<T1,T2,T3>::IsT2() const{
    if (t2 != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool BTreeItem<T1,T2,T3>::IsT3() const{
    if (t3 != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> std::shared_ptr<T1> BTreeItem<T1, T2, T3>::GetT1()
{
	return this->t1;
}
template <class T1, class T2, class T3> std::shared_ptr<T2> BTreeItem<T1, T2, T3>::GetT2()
{
	return this->t2;
}
template <class T1, class T2, class T3> std::shared_ptr<T3> BTreeItem<T1, T2, T3>::GetT3()
{
	return this->t3;
}
template <class T1, class T2, class T3> double BTreeItem<T1, T2, T3>::Area()
{
	if(t1) return t1->Area();
	else if(t2) return t2->Area();
	else if(t3) return t3->Area();
	return 0;
}
template <class T1, class T2, class T3> void * BTreeItem<T1, T2, T3>::operator new(size_t size){
    return arritem_allocator.allocate();
}

template <class T1, class T2, class T3> void BTreeItem<T1, T2, T3>::operator delete(void *ptr){
    arritem_allocator.deallocate(ptr);
}
template <class A1, class A2, class A3> std::ostream& operator << (std::ostream &os, const BTreeItem<A1, A2, A3> & item){
	if (item.IsT1())
		os << *item.t1 << " (прямоугольник)";
	else if (item.IsT2())
		os << *item.t2 << " (ромб)";
	else if (item.IsT3())
		os << *item.t3 << " (трапеция)";
	else
		os << "Пусто";
	return os;
}
template <class T1, class T2, class T3> BTreeItem<T1, T2, T3>::~BTreeItem(){

}
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
template class BTreeItem<Rectangle, Rhombus, Trapezium>;
template std::ostream& operator <<(std::ostream & os,const BTreeItem<Rectangle, Rhombus, Trapezium> & item);

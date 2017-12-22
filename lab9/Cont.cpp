#include "Cont.h"
#include <iostream>
#include <algorithm>

template <class T1, class T2, class T3> Cont<T1, T2, T3>::Cont(int size){
    a = new ContItem<T1, T2, T3>[size];
	size_ = size;
	for (int i = 0; i < size; i++) a[i].SetIndex(i);
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::push(std::shared_ptr<T1> && t, int index){
    a[index]=ContItem<T1, T2, T3>(t, index);
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::push(std::shared_ptr<T2> && t, int index){
    a[index]=ContItem<T1, T2, T3>(t, index);
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::push(std::shared_ptr<T3> && t, int index){
    a[index]=ContItem<T1, T2, T3>(t, index);
}
template <class T1, class T2, class T3> bool Cont<T1, T2, T3>::IsT1(int index){
    return a[index].IsT1();
}
template <class T1, class T2, class T3> bool Cont<T1, T2, T3>::IsT2(int index){
    return a[index].IsT2();
}
template <class T1, class T2, class T3> bool Cont<T1, T2, T3>::IsT3(int index){
    return a[index].IsT3();
}
template <class T1, class T2, class T3> std::shared_ptr<T1> Cont<T1, T2, T3>::GetT1(int index){
    return a[index].GetT1();
}
template <class T1, class T2, class T3> std::shared_ptr<T2> Cont<T1, T2, T3>::GetT2(int index){
    return a[index].GetT2();
}
template <class T1, class T2, class T3> std::shared_ptr<T3> Cont<T1, T2, T3>::GetT3(int index){
    return a[index].GetT3();
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::removeIt(int index){
    a[index] = ContItem<T1, T2, T3>();
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::removeIt_area(double area_){
    for (int i = 0; i < size_; i++){
		if (a[i].Area_() < area_) removeIt(i);
	}
}
template <class A1, class A2, class A3> std::ostream& operator <<(std::ostream & os,const Cont<A1, A2, A3> & cont){
    for(int i=0;i<size;i++){
        os << "[" << i << "] - " << cont.a[i] << std::endl;
    }
    return os;
}
template <class T1, class T2, class T3> Iterator<T1, T2, T3> Cont<T1, T2, T3>::begin()
{
	return Iterator<T1, T2, T3>(a);
}
template <class T1, class T2, class T3> Iterator<T1, T2, T3> Cont<T1, T2, T3>::end()
{
	return Iterator<T1, T2, T3>(&a[size_]);
}
template <class T1, class T2, class T3> Cont<T1, T2, T3>::~Cont(){
    for (int i = 0; i < size; i++) a[i] = ContItem<T1, T2, T3>();
}
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
template class Cont<Rectangle, Rhombus, Trapezium>;
template std::ostream& operator <<(std::ostream & os,const Cont<Rectangle, Rhombus, Trapezium> & cont);

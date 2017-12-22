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
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::QuickSort(int L, int R){
    int left = L;
	int right = R;

	double middle = a[(right + left) / 2].Area_();

	do
	{
		while (a[left].Area_() < middle) left++;
		while (a[right].Area_() > middle) right--;

		if (left <= right)
		{
			if (a[left].Area_() > a[right].Area_()) std::swap(a[left], a[right]);
			left++;
			right--;
		}
	} while (left <= right);

	if (right > L) QuickSort(L, right);
	if (left < R) QuickSort(left, R);
}
template <class T1, class T2, class T3>
std::future<void> Cont<T1, T2, T3>::QuickSortInBackground(int L, int R)
{
	std::packaged_task<void(int, int)> task
	(
		std::bind
		(
			&Cont<T1, T2, T3>::QuickSortParallel,
			this,
			std::placeholders::_1,
			std::placeholders::_2
		)
	);
	std::future<void> res(task.get_future());
	std::thread th(std::move(task), L, R);
	th.detach();
	return res;
}

template <class T1, class T2, class T3>
void Cont<T1, T2, T3>::QuickSortParallel(int L, int R)
{
	int left = L;
	int right = R;

	double middle = a[(right + left) / 2].Area_();

	do
	{
		while (a[left].Area_() < middle) left++;
		while (a[right].Area_() > middle) right--;

		if (left <= right)
		{
			if (a[left].Area_() > a[right].Area_()) std::swap(a[left], a[right]);
			left++;
			right--;
		}
	} while (left <= right);

	std::future<void> left_res;
	std::future<void> right_res;

	if (right > L) left_res = QuickSortInBackground(L, right);
	if (left < R) right_res = QuickSortInBackground(left, R);
	if (right > L) left_res.get();
	if (left < R) right_res.get();
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

#include "Cont.h"
#include <iostream>

template <class T1, class T2, class T3> Cont<T1, T2, T3>::Cont(int size){
    a = new ContItem<T1, T2, T3>[size];
	size_ = size;
	for (int i = 0; i < size; i++) a[i].SetIndex(i);
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::push(std::shared_ptr<T1> && t, int index){
    std::shared_ptr<BTree<T1,T2,T3>> item = std::make_shared<BTree<T1,T2,T3>>(t);
    a[index]=ContItem<T1, T2, T3>(item, index);
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::push(std::shared_ptr<T2> && t, int index){
    std::shared_ptr<BTree<T1,T2,T3>> item = std::make_shared<BTree<T1,T2,T3>>(t);
    a[index]=ContItem<T1, T2, T3>(item, index);
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::push(std::shared_ptr<T3> && t, int index){
    std::shared_ptr<BTree<T1,T2,T3>> item = std::make_shared<BTree<T1,T2,T3>>(t);
    a[index]=ContItem<T1, T2, T3>(item, index);
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::removeIt(double area, int index,int number){
    if(number == 1){
        std::shared_ptr<BTreeItem<T1,T2,T3>> item = a[index].t->head;
        for(int i=1; i<6; i++){
            if(item->Area() < area){
                a[index].t->remove(item->Area());
                a[index].t->size_--;
                item = a[index].t->head;
                continue;
            }
            else if(item->leftT){
                item = item->leftT;
                continue;
            }
            else if(item->rightT){
                item = item->rightT;
                continue;
            }
        }
        return;
    }
    else if(number == 2){
        a[index].t->remove(area);
        a[index].t->size_--;
        return;
    }
    else if(number == 3){
        std::shared_ptr<BTreeItem<T1,T2,T3>> item = a[index].t->head;
        for(int i=1; i<6; i++){
            if(item->Area() > area){
                a[index].t->remove(item->Area());
                a[index].t->size_--;
                item = a[index].t->head;
                continue;
            }
            else if(item->rightT){
                item = item->rightT;
                continue;
            }
            else if(item->leftT){
                item = item->leftT;
                continue;
            }
        }
        return;
    }
}
template <class T1, class T2, class T3> void Cont<T1, T2, T3>::removeIt(int index,int number){
    if(number == 1){
        std::shared_ptr<BTreeItem<T1,T2,T3>> item = a[index].t->head;
        for(int i=1; i<6; i++){
            if(item->IsT1()){
                a[index].t->remove(item->Area());
                a[index].t->size_--;
                item = a[index].t->head;
                continue;
            }
            else if(item->leftT){
                item = item->leftT;
                continue;
            }
            else if(item->rightT){
                item = item->rightT;
                continue;
            }
        }
        return;
    }
    else if(number == 2){
        std::shared_ptr<BTreeItem<T1,T2,T3>> item = a[index].t->head;
        for(int i=1; i<6; i++){
            if(item->IsT2()){
                a[index].t->remove(item->Area());
                a[index].t->size_--;
                item = a[index].t->head;
                continue;
            }
            else if(item->leftT){
                item = item->leftT;
                continue;
            }
            else if(item->rightT){
                item = item->rightT;
                continue;
            }
        }
        return;
    }
    else if(number == 3){
        std::shared_ptr<BTreeItem<T1,T2,T3>> item = a[index].t->head;
        for(int i=1; i<6; i++){
            if(item->IsT3()){
                a[index].t->remove(item->Area());
                a[index].t->size_--;
                item = a[index].t->head;
                continue;
            }
            else if(item->leftT){
                item = item->leftT;
                continue;
            }
            else if(item->rightT){
                item = item->rightT;
                continue;
            }
        }
        return;
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

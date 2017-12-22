#include "Cont.h"
#include <iostream>

Cont::Cont(){
    for (int i = 0; i < size; i++) a[i] = ContItem();
}
void Cont::push(std::shared_ptr<Rectangle> &&rectangle, int index){
    a[index]=ContItem(rectangle);
}
void Cont::push(std::shared_ptr<Rhombus> &&rhombus, int index){
    a[index]=ContItem(rhombus);
}
void Cont::push(std::shared_ptr<Trapezium> &&trapezium, int index){
    a[index]=ContItem(trapezium);
}
bool Cont::IsRectangle(int index){
    return a[index].IsRectangle();
}
bool Cont::IsRhombus(int index){
    return a[index].IsRhombus();
}
bool Cont::IsTrapezium(int index){
    return a[index].IsTrapezium();
}
std::shared_ptr<Rectangle> Cont::GetRectangle(int index){
    return a[index].GetRectangle();
}
std::shared_ptr<Rhombus> Cont::GetRhombus(int index){
    return a[index].GetRhombus();
}
std::shared_ptr<Trapezium> Cont::GetTrapezium(int index){
    return a[index].GetTrapezium();
}
void Cont::removeIt(int index){
    a[index] = ContItem();
}
std::ostream& operator <<(std::ostream & os,const Cont & cont){
    for(int i=0;i<size;i++){
        os << "[" << i << "] - " << cont.a[i] << std::endl;
    }
    return os;
}
Cont::~Cont(){
    for (int i = 0; i < size; i++) a[i] = ContItem();
}

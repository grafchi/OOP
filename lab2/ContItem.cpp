#include "ContItem.h"
#include <iostream>

ContItem::ContItem(const Rectangle & rectangle){
    this->rectangle = rectangle;
    this->next = nullptr;
}
ContItem* ContItem::SetNext(ContItem* next){
    ContItem* old = this->next;
    this->next = next;
    return old;
}
ContItem* ContItem::GetNext(){
    return this->next;
}
Rectangle ContItem::GetRectangle() const{
    return this->rectangle;
}
std::ostream& operator <<(std::ostream & os, const ContItem & obj){
    os<<"["<<obj.rectangle<<"]"<<std::endl;
    return os;
}
ContItem::~ContItem(){
    delete next;
}

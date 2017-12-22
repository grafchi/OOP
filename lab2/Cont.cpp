#include "Cont.h"
#include <iostream>

Cont::Cont(){
    head=nullptr;
}
void Cont::push(Rectangle &rectangle){
    ContItem *other = new ContItem(rectangle);
    other->SetNext(head);
    head = other;
    std::cout<<"Фигура добавлена"<<std::endl;
}
Rectangle Cont::pop(){
    Rectangle result;
    if (head != nullptr) {
    ContItem *old_head = head;
    head = head->GetNext();
    result = old_head->GetRectangle();
    old_head->SetNext(nullptr);
    delete old_head;
}
return result;
}
void Cont::removeIt(){
    ContItem *old_head=head;
    if(old_head==nullptr){
        std::cout<<"Стек пуст"<<std::endl;
        return;
    }
    head=head->GetNext();
    old_head->SetNext(nullptr);
    delete old_head;
    std::cout<<"Фигура удалена"<<std::endl;
}
ContItem* Cont::getHead(){
    return this->head;
}
std::ostream& operator <<(std::ostream & os,const Cont & con){
    ContItem *item = con.head;
    if(item==nullptr) std::cout<<"Стек пуст"<<std::endl;
    while(item!=nullptr)
    {
    os << *item;
    item = item->GetNext();
    }
    return os;
}
Cont::~Cont(){
    delete head;
}

#include "Rhombus.h"
#include <iostream>

Rhombus::Rhombus(){
    side=0.0;
    height=0.0;
}
Rhombus::Rhombus(std::istream & is){
    is>>*this;
}
std::ostream& operator <<(std::ostream & os, const Rhombus & obj){
    os<<"Сторона = "<<obj.side<<", Высота = "<<obj.height;
    return os;
}
std::istream& operator >>(std::istream & is, Rhombus & obj){
    std::cout<<"Введите сторону: "<<std::endl;
    if(!(is>>obj.side)){
        is.clear();
        while(is.get() !='\n');
        obj.err=true;
        return is;
    }
    std::cout<<"Введите высоту: "<<std::endl;
    if(!(is>>obj.height)){
        is.clear();
        while(is.get() !='\n');
        obj.err=true;
        return is;
    }
    if(obj.side<0 || obj.height<0) obj.err=true;
    return is;
}
Rhombus::~Rhombus(){
   //std::cout << "Ромб удален" << std::endl;
}


#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(){
    side_a=0.0;
    side_b=0.0;
}
Rectangle::Rectangle(std::istream & is){
    is>>*this;
}
std::ostream& operator <<(std::ostream & os, const Rectangle & obj){
    os<<"Сторона а= "<<obj.side_a<<", Сторона b= "<<obj.side_b;
    return os;
}
std::istream& operator >>(std::istream & is, Rectangle & obj){
    std::cout<<"Введите сторону a: "<<std::endl;
    if(!(is>>obj.side_a)){
        is.clear();
        while(is.get() !='\n');
        obj.err=true;
        return is;
    }
    std::cout<<"Введите сторону b: "<<std::endl;
    if(!(is>>obj.side_b)){
        is.clear();
        while(is.get() !='\n');
        obj.err=true;
        return is;
    }
    if(obj.side_a<0 || obj.side_b<0) obj.err=true;
    return is;
}
Rectangle::~Rectangle(){
   //std::cout << "Прямоугольник удален" << std::endl;
}


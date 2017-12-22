#include "Trapezium.h"
#include <iostream>

Trapezium::Trapezium(){
    side_a=0.0;
    side_b=0.0;
    height=0.0;
}
Trapezium::Trapezium(std::istream & is){
    is>>*this;
}
std::ostream& operator <<(std::ostream & os, const Trapezium & obj){
    os<<"Сторона а= "<<obj.side_a<<", Сторона b= "<<obj.side_b<<", Высота = "<<obj.height;
    return os;
}
std::istream& operator >>(std::istream & is, Trapezium & obj){
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
    std::cout<<"Введите высоту: "<<std::endl;
    if(!(is>>obj.height)){
        is.clear();
        while(is.get() !='\n');
        obj.err=true;
        return is;
    }
    if(obj.side_a<0 || obj.side_b<0 || obj.height<0) obj.err=true;
    return is;
}
Trapezium::~Trapezium(){
   //std::cout << "Трапеция удален" << std::endl;
}


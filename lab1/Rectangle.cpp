#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(){
    side_a=0.0;
    side_b=0.0;
}
Rectangle::Rectangle(std::istream& is){
    std::cout<<"������� ������� a: "<<std::endl;
    if(!(is>>side_a)){
        is.clear();
        while(is.get() !='\n');
        err=true;
        return;
    }
    std::cout<<"������� ������� b: "<<std::endl;
    if(!(is>>side_b)){
        is.clear();
        while(is.get() !='\n');
        err=true;
        return;
    }
    if(side_a<0 || side_b<0) err=true;
}
void Rectangle::Print(){
    std::cout<<"��� ������: �������������"<<std::endl;
    std::cout<<"������� a= "<<side_a<<std::endl;
    std::cout<<"������� b= "<<side_b<<std::endl;
}
double Rectangle::Square(){
    return side_a*side_b;
}

#include "Trapezium.h"

Trapezium::Trapezium(){
    side_a=0.0;
    side_b=0.0;
    height=0.0;
}
Trapezium::Trapezium(std::istream& is){
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
    std::cout<<"������� ������: "<<std::endl;
    if(!(is>>height)){
        is.clear();
        while(is.get() !='\n');
        err=true;
        return;
    }
    if(side_a<0 || side_b<0 || height<0) err=true;
}
void Trapezium::Print(){
    std::cout<<"��� ������: ��������"<<std::endl;
    std::cout<<"������� a= "<<side_a<<std::endl;
    std::cout<<"������� b= "<<side_b<<std::endl;
    std::cout<<"������= "<<height<<std::endl;
}
double Trapezium::Square(){
    return (side_a+side_b)/2.0*height;
}


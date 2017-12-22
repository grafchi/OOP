#include "Rhombus.h"

Rhombus::Rhombus(){
    side=0.0;
    height=0.0;
}
Rhombus::Rhombus(std::istream& is){
    std::cout<<"������� �������: "<<std::endl;
    if(!(is>>side)){
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
    if(height>side){
        err=true;
        return;
    }
}
void Rhombus::Print(){
    std::cout<<"��� ������: ����"<<std::endl;
    std::cout<<"�������= "<<side<<std::endl;
    std::cout<<"������= "<<height<<std::endl;
}
double Rhombus::Square(){
    return side*height;
}


#include <iostream>
#include <clocale>
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"

void test(Figure* figure){
    if(figure->err){
        std::cout<<"������������ ������� ������"<<std::endl;
        return;
    }
    figure->Print();
    std::cout<<"������� ������= "<<figure->Square()<<std::endl;
    delete figure;
}

int main()
{
    setlocale(LC_CTYPE,"rus");
    int a;
    do{
        std::cout<<"1) �������������\n"<<"2) ��������\n"<<"3) ����\n"<<"4) �����\n"<<"�������� ��������: "<<std::endl;
        if(!(std::cin>>a)){
            std::cin.clear();
            while(std::cin.get() !='\n');
        }
        switch(a){
            case 1:
                test(new Rectangle(std::cin));
                break;
            case 2:
                test(new Trapezium(std::cin));
                break;
            case 3:
                test(new Rhombus(std::cin));
                break;
            case 4: break;
            default:
                std::cout<<"������. ������ ������ ���� �� ����������\n"<<std::endl;
                break;
        }
    }while(a!=4);
    return 0;
}

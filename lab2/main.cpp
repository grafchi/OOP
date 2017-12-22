#include <iostream>
#include <clocale>
#include "Rectangle.h"
#include "ContItem.h"
#include "Cont.h"

int main()
{
    setlocale(LC_CTYPE,"rus");
    Cont container;
    int a;
    do{
        std::cout<<"1) �������� ������\n2) ������� ����������\n3) ������� ������\n4) �����\n"<<std::endl;
        if(!(std::cin>>a)){
            std::cin.clear();
            while(std::cin.get() !='\n');
        }
        switch(a){
        case 1:{
            Rectangle rect(std::cin);
            if(rect.err){
                std::cout<<"������������ ������� ������"<<std::endl;
                break;
            }
            container.push(rect);
            break;}
        case 2:
            std::cout<<container;
            break;
        case 3:
            container.removeIt();
            break;
        case 4:break;
        default:
            std::cout<<"������. ������ ������ ���� �� ����������\n"<<std::endl;
            break;
        }
    }while(a!=4);
    return 0;
}

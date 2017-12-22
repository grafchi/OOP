#include <iostream>
#include <clocale>
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include <memory>
#include "ContItem.h"
#include "Cont.h"

int main()
{
    setlocale(LC_CTYPE,"rus");
    Cont<Rectangle, Rhombus, Trapezium> container;
    int a;
    do{
        std::cout<<"1) �������� ������\n2) ������� ����������\n3) ������� ������\n4) ������� ������\n5) �����\n"<<std::endl;
        if(!(std::cin>>a)){
            std::cin.clear();
            while(std::cin.get() !='\n');
        }
        switch(a){
        case 1:{
            std::cout << "1) �������������\n2) ����\n3) ��������\n" << std::endl;
            int v,i;
            std::cin >> v;
            std::cout << "������� ������ ";
            std::cin >> i;
            switch(v){
            case 1:
                container.push(std::shared_ptr<Rectangle>(new Rectangle(std::cin)), i);
                break;
            case 2:
                container.push(std::shared_ptr<Rhombus>(new Rhombus(std::cin)), i);
                break;
            case 3:
                container.push(std::shared_ptr<Trapezium>(new Trapezium(std::cin)), i);
                break;
            default:
                std::cout<<"������. ������ ������ ���� �� ����������\n"<<std::endl;
                break;
            }
            break;}
        case 2:
            std::cout<<container;
            break;
        case 3:
            std::cout << "������� ������ ";
            int ind;
            std::cin >> ind;
            container.removeIt(ind);
            break;
        case 4:
            std::cout << "������� ������ ";
            int i;
            std::cin >> i;
            if (container.IsT1(i))
				std::cout << *container.GetT1(i) << std::endl;
			else if (container.IsT2(i))
				std::cout << *container.GetT2(i) << std::endl;
			else if (container.IsT3(i))
				std::cout << *container.GetT3(i) << std::endl;
			else
				std::cout << "������ �������" << std::endl;
            break;
        case 5:break;
        default:
            std::cout<<"������. ������ ������ ���� �� ����������\n"<<std::endl;
            break;
        }
    }while(a!=5);
    return 0;
}

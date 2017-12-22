#include <iostream>
#include <clocale>
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include <memory>
#include "ContItem.h"
#include "Cont.h"
#include "BTree.h"
#include "Allocator.h"

int main()
{
    setlocale(LC_CTYPE,"rus");
    Cont<Rectangle, Rhombus, Trapezium> container(10);
    int a;
    do{
        std::cout<<"1) �������� ������\n2) ������� ����������\n3) ������� ������\n4) �����\n"<<std::endl;
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
            int ind_1;
            std::cout << "1) 1-�� ���������\n2) 2-�� ���������\n" << std::endl;
            std::cin >> ind_1;
            switch(ind_1){
            case 1:
                for (auto i : container) std::cout << *i << std::endl;
                break;
            case 2:
                int ind_2;
                std::cout << "������� ������ ";
                std::cin >> ind_2;
                std::cout << container.a[ind_2] << std::endl;
                break;
            default:
                std::cout<<"������. ������ ������ ���� �� ����������\n"<<std::endl;
                break;
            }
            break;
        case 3:{
            std::cout << "������� ������: ";
            int ind_1,ind;
            std::cin >> ind;
            std::cout << "1) �� ���� ������\n2) �� �������\n" << std::endl;
            std::cin >> ind_1;
            switch(ind_1){
            case 1:{
                int ind_2;
                std::cout << "1) �������������\n2) ����\n3) ��������\n" << std::endl;
                std::cin >> ind_2;
                container.removeIt(ind,ind_2);
                break; }
            case 2:{
                int ind_2;
                double area;
                std::cout << "1) < ��������\n2) == ��������\n3) > ��������\n" << std::endl;
                std::cin >> ind_2;
                std::cout << "������� �������: " << std::endl;
                std::cin >> area;
                container.removeIt(area,ind,ind_2);
                break; }
            default:{
                std::cout<<"������. ������ ������ ���� �� ����������\n"<<std::endl;
                break; }
            }
            break;
        /*case 4:
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
            break; */
        case 4:break;
        default:{
            std::cout<<"������. ������ ������ ���� �� ����������\n"<<std::endl;
            break; }
        }
    }}while(a!=4);
    return 0;
}


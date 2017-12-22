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
        std::cout<<"1) Добавить фигуру\n2) Вывести содержимое\n3) Удалить фигуру\n4) Выход\n"<<std::endl;
        if(!(std::cin>>a)){
            std::cin.clear();
            while(std::cin.get() !='\n');
        }
        switch(a){
        case 1:{
            std::cout << "1) Прямоугольник\n2) Ромб\n3) Трапеция\n" << std::endl;
            int v,i;
            std::cin >> v;
            std::cout << "Введите индекс ";
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
                std::cout<<"Ошибка. Такого пункта меню не существует\n"<<std::endl;
                break;
            }
            break;}
        case 2:
            int ind_1;
            std::cout << "1) 1-ый контейнер\n2) 2-ой контейнер\n" << std::endl;
            std::cin >> ind_1;
            switch(ind_1){
            case 1:
                for (auto i : container) std::cout << *i << std::endl;
                break;
            case 2:
                int ind_2;
                std::cout << "Введите индекс ";
                std::cin >> ind_2;
                std::cout << container.a[ind_2] << std::endl;
                break;
            default:
                std::cout<<"Ошибка. Такого пункта меню не существует\n"<<std::endl;
                break;
            }
            break;
        case 3:{
            std::cout << "Введите индекс: ";
            int ind_1,ind;
            std::cin >> ind;
            std::cout << "1) по типу фигуры\n2) по площади\n" << std::endl;
            std::cin >> ind_1;
            switch(ind_1){
            case 1:{
                int ind_2;
                std::cout << "1) Прямоугольник\n2) Ромб\n3) Трапеция\n" << std::endl;
                std::cin >> ind_2;
                container.removeIt(ind,ind_2);
                break; }
            case 2:{
                int ind_2;
                double area;
                std::cout << "1) < значения\n2) == значению\n3) > значения\n" << std::endl;
                std::cin >> ind_2;
                std::cout << "Введите площадь: " << std::endl;
                std::cin >> area;
                container.removeIt(area,ind,ind_2);
                break; }
            default:{
                std::cout<<"Ошибка. Такого пункта меню не существует\n"<<std::endl;
                break; }
            }
            break;
        /*case 4:
            std::cout << "Введите индекс ";
            int i;
            std::cin >> i;
            if (container.IsT1(i))
				std::cout << *container.GetT1(i) << std::endl;
			else if (container.IsT2(i))
				std::cout << *container.GetT2(i) << std::endl;
			else if (container.IsT3(i))
				std::cout << *container.GetT3(i) << std::endl;
			else
				std::cout << "Пустой элемент" << std::endl;
            break; */
        case 4:break;
        default:{
            std::cout<<"Ошибка. Такого пункта меню не существует\n"<<std::endl;
            break; }
        }
    }}while(a!=4);
    return 0;
}


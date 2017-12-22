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
    Cont container;
    int a;
    do{
        std::cout<<"1) Добавить фигуру\n2) Вывести содержимое\n3) Удалить фигуру\n4) Вывести фигуру\n5) Выход\n"<<std::endl;
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
            std::cout<<container;
            break;
        case 3:
            std::cout << "Введите индекс ";
            int ind;
            std::cin >> ind;
            container.removeIt(ind);
            break;
        case 4:
            std::cout << "Введите индекс ";
            int i;
            std::cin >> i;
            if (container.IsRectangle(i))
				std::cout << *container.GetRectangle(i) << std::endl;
			else if (container.IsRhombus(i))
				std::cout << *container.GetRhombus(i) << std::endl;
			else if (container.IsTrapezium(i))
				std::cout << *container.GetTrapezium(i) << std::endl;
			else
				std::cout << "Пустой элемент" << std::endl;
            break;
        case 5:break;
        default:
            std::cout<<"Ошибка. Такого пункта меню не существует\n"<<std::endl;
            break;
        }
    }while(a!=5);
    return 0;
}

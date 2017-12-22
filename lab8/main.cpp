#include <iostream>
#include <clocale>
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include <memory>
#include "ContItem.h"
#include "Cont.h"
#include "Allocator.h"
#include <future>

int main()
{
    setlocale(LC_CTYPE,"rus");
    Cont<Rectangle, Rhombus, Trapezium> container(10);
    int a;
    do{
        std::cout<<"1) Добавить фигуру\n2) Вывести содержимое\n3) Удалить фигуру\n4) Вывести фигуру\n5) Сортировка\n6) Параллельная сортировка\n7) Выход\n"<<std::endl;
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
            for (auto i : container) std::cout << *i << std::endl;
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
            if (container.IsT1(i))
				std::cout << *container.GetT1(i) << std::endl;
			else if (container.IsT2(i))
				std::cout << *container.GetT2(i) << std::endl;
			else if (container.IsT3(i))
				std::cout << *container.GetT3(i) << std::endl;
			else
				std::cout << "Пустой элемент" << std::endl;
            break;
        case 5:
            container.QuickSort(0,9);
            break;
        case 6:
            container.QuickSortParallel(0,9);
            break;
        case 7:break;
        default:
            std::cout<<"Ошибка. Такого пункта меню не существует\n"<<std::endl;
            break;
        }
    }while(a!=7);
    return 0;
}

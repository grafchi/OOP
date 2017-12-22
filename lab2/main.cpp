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
        std::cout<<"1) Добавить фигуру\n2) Вывести содержимое\n3) Удалить фигуру\n4) Выход\n"<<std::endl;
        if(!(std::cin>>a)){
            std::cin.clear();
            while(std::cin.get() !='\n');
        }
        switch(a){
        case 1:{
            Rectangle rect(std::cin);
            if(rect.err){
                std::cout<<"Некорректные входные данные"<<std::endl;
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
            std::cout<<"Ошибка. Такого пункта меню не существует\n"<<std::endl;
            break;
        }
    }while(a!=4);
    return 0;
}

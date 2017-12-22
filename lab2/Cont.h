#ifndef CONT.H
#define CONT.H

#include "Rectangle.h"
#include "ContItem.h"

class Cont{
public:
    Cont();

    void push(Rectangle &rectangle);
    Rectangle pop();
    void removeIt();
    ContItem* getHead();
    friend std::ostream& operator <<(std::ostream & os,const Cont & con);
    virtual ~Cont();
private:
    ContItem *head;
};
#endif

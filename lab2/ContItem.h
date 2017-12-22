#ifndef CONTITEM_H
#define CONTITEM_H

#include "Rectangle.h"

class ContItem{
public:
    ContItem(const Rectangle & rectangle);
    //ContItem(const ContItem& orig);
    ContItem* SetNext(ContItem* next);
    ContItem* GetNext();
    Rectangle GetRectangle() const;
    friend std::ostream& operator <<(std::ostream & os, const ContItem & obj);
    virtual ~ContItem();
private:
    Rectangle rectangle;
    ContItem *next;
};
#endif

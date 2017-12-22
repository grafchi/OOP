#ifndef FIGURE_H
#define FIGURE_H

class Figure{
public:
    bool err=false;
    virtual double Area()=0;
    virtual ~Figure() {}
};

#endif


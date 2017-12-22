#ifndef CONTITEM_H
#define CONTITEM_H

#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"
#include "Figure.h"
#include <memory>
class ContItem{
public:
    ContItem();
	ContItem(std::shared_ptr<Rectangle> &rectangle);
	ContItem(std::shared_ptr<Rhombus> &rhombus);
	ContItem(std::shared_ptr<Trapezium> &trapezium);

	bool IsRectangle() const;
	bool IsRhombus() const;
	bool IsTrapezium() const;

	std::shared_ptr<Rectangle> GetRectangle();
	std::shared_ptr<Rhombus> GetRhombus();
	std::shared_ptr<Trapezium> GetTrapezium();

    friend std::ostream& operator<< (std::ostream & os, const ContItem & item);
    virtual ~ContItem();
private:
    std::shared_ptr<Rectangle> rectangle;
	std::shared_ptr<Rhombus> rhombus;
	std::shared_ptr<Trapezium> trapezium;
};
#endif


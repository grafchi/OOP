#include "ContItem.h"

ContItem::ContItem() : rectangle(nullptr), rhombus(nullptr), trapezium(nullptr) {}
ContItem::ContItem(std::shared_ptr<Rectangle> &rectangle) : rectangle(rectangle), rhombus(nullptr), trapezium(nullptr) {}
ContItem::ContItem(std::shared_ptr<Rhombus> &rhombus) : rectangle(nullptr), rhombus(rhombus), trapezium(nullptr) {}
ContItem::ContItem(std::shared_ptr<Trapezium> &trapezium) : rectangle(nullptr), rhombus(nullptr), trapezium(trapezium) {}
ContItem::~ContItem() {}
bool ContItem::IsRectangle() const
{
	if (rectangle != nullptr) return true;
	else return false;
}
bool ContItem::IsRhombus() const
{
	if (rhombus != nullptr) return true;
	else return false;
}
bool ContItem::IsTrapezium() const
{
	if (trapezium != nullptr) return true;
	else return false;
}
std::shared_ptr<Rectangle> ContItem::GetRectangle()
{
	return this->rectangle;
}
std::shared_ptr<Rhombus> ContItem::GetRhombus()
{
	return this->rhombus;
}
std::shared_ptr<Trapezium> ContItem::GetTrapezium()
{
	return this->trapezium;
}
std::ostream& operator << (std::ostream &os, const ContItem &item)
{
	if (item.IsRectangle())
		os << *item.rectangle << " (прямоугольник)";
	else if (item.IsRhombus())
		os << *item.rhombus << " (ромб)";
	else if (item.IsTrapezium())
		os << *item.trapezium << " (трапеция)";
	else
		os << "Пусто";
	return os;
}

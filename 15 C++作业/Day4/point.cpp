#include "point.h"

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::~Point()
{
}

//����x 
int Point::ReturnPosX() const
{
	return this->x;
}

int Point::ReturnPosY() const
{
	return this->y;
}

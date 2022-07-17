#include "line.h"

Line::Line(int size, COLORREF color)
{
	this->size = size;
	this->color = color;
}

Line::~Line()
{
}

int& Line::changeLine()
{
	// TODO: 在此处插入 return 语句
	return this->size;
}

void Line::MouseDrawLine(ExMessage msg)
{
	if (msg.message == WM_LBUTTONDOWN)
	{
		isDown = true;				//鼠标按下
		pos = Point(msg.x, msg.y);	//记录鼠标开始按下的坐标
	}
	if (msg.message == WM_LBUTTONUP)
	{
		isDown = false;				//鼠标松开
	}
	if (msg.message == WM_MOUSEMOVE && isDown)
	{
		setlinestyle(PS_SOLID, this->size);
		setlinecolor(this->color);
		line(pos.ReturnPosX(), pos.ReturnPosY(), msg.x, msg.y);
	}
	//坐标的位置更新
	pos = Point(msg.x, msg.y);
}

void Line::WScontrolLineStyle()
{
	if (_kbhit())
	{
		switch(_getch())
		{
		case 'w':
		case 'W':
		case 72:
			if (size <= 10)
			{
				size++;
				std::cout << size << std::endl;
			}
			break;
		case 's':
		case 'S':
		case 80:
			if (size >= 1)
			{
				size--;
			}	//72 80 75 77
			break;
		}
	}
}

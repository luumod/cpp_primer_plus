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
	// TODO: �ڴ˴����� return ���
	return this->size;
}

void Line::MouseDrawLine(ExMessage msg)
{
	if (msg.message == WM_LBUTTONDOWN)
	{
		isDown = true;				//��갴��
		pos = Point(msg.x, msg.y);	//��¼��꿪ʼ���µ�����
	}
	if (msg.message == WM_LBUTTONUP)
	{
		isDown = false;				//����ɿ�
	}
	if (msg.message == WM_MOUSEMOVE && isDown)
	{
		setlinestyle(PS_SOLID, this->size);
		setlinecolor(this->color);
		line(pos.ReturnPosX(), pos.ReturnPosY(), msg.x, msg.y);
	}
	//�����λ�ø���
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

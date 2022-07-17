


#ifndef LINE_H_
#define LINE_H_

#include <iostream>
#include <conio.h>
#include "point.h"

//����
class Line
{
private:
	Point pos;		//����
	bool isDown = false;		//�Ƿ��±��

	int size;		//�ߵĴ�ϸ
	COLORREF color;	//�ߵ���ɫ
public:
	Line(int size = 2, COLORREF color = BLACK);
	~Line();
	
	//�޸��ߵĴ�ϸ
	int& changeLine();
	//������
	void MouseDrawLine(ExMessage msg);
	//�����ߵĴ�ϸ
	void WScontrolLineStyle();
};

#endif

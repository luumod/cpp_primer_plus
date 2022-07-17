


#ifndef LINE_H_
#define LINE_H_

#include <iostream>
#include <conio.h>
#include "point.h"

//线类
class Line
{
private:
	Point pos;		//点类
	bool isDown = false;		//是否按下标记

	int size;		//线的粗细
	COLORREF color;	//线的颜色
public:
	Line(int size = 2, COLORREF color = BLACK);
	~Line();
	
	//修改线的粗细
	int& changeLine();
	//鼠标操作
	void MouseDrawLine(ExMessage msg);
	//控制线的粗细
	void WScontrolLineStyle();
};

#endif

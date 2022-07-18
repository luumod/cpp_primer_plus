#pragma once
#include "rect.h"
#include "Timer.h"

/*
光标
*/
class Curcos
{
private:
	Timer time;		//时间控制
	Rect pos;
	int count;		//控制显示
public:
	Curcos(int x, int y, int w, int h, COLORREF color);
	void Show();
	void Draw();
	void Clear();
	void Setcrcos(int x, int y);
};
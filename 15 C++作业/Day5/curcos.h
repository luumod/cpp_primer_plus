#pragma once
#include "rect.h"
#include "Timer.h"

/*
���
*/
class Curcos
{
private:
	Timer time;		//ʱ�����
	Rect pos;
	int count;		//������ʾ
public:
	Curcos(int x, int y, int w, int h, COLORREF color);
	void Show();
	void Draw();
	void Clear();
	void Setcrcos(int x, int y);
};
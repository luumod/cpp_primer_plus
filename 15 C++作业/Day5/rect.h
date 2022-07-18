#pragma once
#include "common.h"

/*
矩形输入框
*/
class Rect
{
private:
	int x;
	int y;
	int w;
	int h;
	COLORREF Curcolor;
	COLORREF Oldcolor;
public:
	Rect(int x = 100, int y = 100, int w = EDIT_W, int h = EDIT_H, COLORREF color = RGB(189, 189, 189));
	//外部访问接口
	int GetX()const;
	int GetY()const;
	int GetW()const;
	int GEtH()const;
	//外部修改接口
	void SetX(int x);
	void SetY(int y);
	void SetW(int w);
	void SetH(int h);
	void Setcolor(COLORREF color);
	void Resetcolor();
	//绘制
	void Draw();
	//判断鼠标位置
	bool MouseInRect(ExMessage msg);
};

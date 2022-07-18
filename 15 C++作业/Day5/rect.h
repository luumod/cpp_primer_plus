#pragma once
#include "common.h"

/*
���������
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
	//�ⲿ���ʽӿ�
	int GetX()const;
	int GetY()const;
	int GetW()const;
	int GEtH()const;
	//�ⲿ�޸Ľӿ�
	void SetX(int x);
	void SetY(int y);
	void SetW(int w);
	void SetH(int h);
	void Setcolor(COLORREF color);
	void Resetcolor();
	//����
	void Draw();
	//�ж����λ��
	bool MouseInRect(ExMessage msg);
};

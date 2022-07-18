#pragma once
#include "common.h"

/*
按钮
*/
class Button
{
private:
	int x;
	int y;
	int w;
	int h;
	COLORREF color;
	COLORREF oldcolor;
	std::wstring text;		//文本
public:
	Button(int x = 100, int y = 200, int w = 100, int h = 50, COLORREF color = WHITE, std::wstring text = L"按钮")
		:x(x), y(y), w(w), h(h), color(color), oldcolor(color), text(text) {}
	void Draw();
	bool MouseInButton(ExMessage msg);
	bool ClickButton(ExMessage msg);
};


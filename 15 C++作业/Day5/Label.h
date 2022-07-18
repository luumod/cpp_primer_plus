#pragma once

#include "common.h"

/*
文字标签
*/
class Label
{
private:
	wstring text;		//文字
	COLORREF color;		//颜色
	int textw;			//文字宽度
	wstring style;		//文字样式
public:
	Label(wstring text);
	void SetLabelstyle(COLORREF color, int textw, wstring tyle);
	void Draw(int x,int y);
	wstring Gettext();
};

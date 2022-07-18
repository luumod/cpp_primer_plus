#include "Label.h"

Label::Label(wstring text)
{
	this->text = text;
	this->color = BLACK;
	this->style = L"ºÚÌå";
	this->textw = 25;
}

void Label::SetLabelstyle(COLORREF color, int textw, wstring style)
{
	this->color = color;
	this->textw = textw;
	this->style = style;
}

void Label::Draw(int x,int y)
{
	setbkmode(TRANSPARENT);
	settextstyle(textw, 0, style.c_str());
	settextcolor(color);
	outtextxy(x, y, text.c_str());
}
wstring Label::Gettext()
{
	return text;
}


#include "rect.h"
#include "register.h"

Rect::Rect(int x, int y, int w, int h, COLORREF color)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->Curcolor = color;
	this->Oldcolor = color;
}

int Rect::GetX() const
{
	return x;
}

int Rect::GetY() const
{
	return y;
}

int Rect::GetW() const
{
	return w;
}

int Rect::GEtH() const
{
	return h;
}

void Rect::SetX(int x)
{
	this->x = x;
}

void Rect::SetY(int y)
{
	this->y = y;
}

void Rect::SetW(int w)
{
	this->w = w;

}

void Rect::SetH(int h)
{
	this->h = h;
}

void Rect::Setcolor(COLORREF color)
{
	this->Curcolor = color;
}

void Rect::Resetcolor()
{
	this->Curcolor = RGB(189, 189, 189);
}

//»­¾ØÐÎ
void Rect::Draw()
{
	setfillcolor(this->Curcolor);
	fillrectangle(x, y, x + w, y + h);
}

bool Rect::MouseInRect(ExMessage msg)
{
	if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
	{
		return true;
	}
	return false;
}

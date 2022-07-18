#include "curcos.h"

Curcos::Curcos(int x, int y, int w, int h, COLORREF color)
	:pos(x,y,w,h,color),time(20,0)
{
	count = 0;
}

void Curcos::Show()
{
	if (time.timer())
	{
		count++;
	}
	Draw();
	Clear();
}

void Curcos::Draw()
{
	if (count % 60 < 30)
	{
		rectangle(pos.GetX(), pos.GetY(),
			pos.GetX() + pos.GetW(), pos.GetY() + pos.GEtH());
	}
}

void Curcos::Clear()
{
	if (count % 60 > 30)
	{
		clearrectangle(pos.GetX(), pos.GetY(),
			pos.GetX() + pos.GetW(), pos.GetY() + pos.GEtH());
	}
}

void Curcos::Setcrcos(int x,int y)
{
	pos.SetX(x);
	pos.SetY(y);
}

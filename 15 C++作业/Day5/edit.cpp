#include "edit.h"

Edit::Edit(int x, int y, int w, int h)
	:rect(x,y,w,h),pos(x,y,1,h-4,BLACK)
{
	textw = 0;
	isinput = false;
	type = EDIT::jiemi;
}

void Edit::TextDraw()
{

	//矩形框
	rect.Draw();
	//文字
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	int y = rect.GetY() + (rect.GEtH() - textheight(text.c_str())) / 2;
	textw = textwidth(this->text.c_str());
	if (type == EDIT::jiemi)
	{
		outtextxy(rect.GetX()+5,y, text.c_str());
	}
	if (type == EDIT::jiami)
	{
		//加密输入
		wstring str;		//存储加密字符
		for (int i = 0; i < text.size(); i++)
		{
			str += L"*";
		}
		textw = textwidth(str.c_str());
		outtextxy(rect.GetX() + 10, y, str.c_str());

	}
	/*
	绘制光标
	*/
	if (isinput == true)
	{
		pos.Setcrcos(rect.GetX() + textw + 15, rect.GetY() + 2);
		pos.Show();
	}
}

bool Edit::MouseInEdit(ExMessage msg)
{
	return rect.MouseInRect(msg);
}

void Edit::OnEvent(ExMessage msg)
{
	switch (msg.message)
	{
	case WM_LBUTTONDOWN:
		if (MouseInEdit(msg))
		{
			rect.Setcolor(WHITE);
			isinput = true;
		}
		else
		{
			rect.Resetcolor();
			isinput = false;
		}
		break;
	case WM_CHAR:
		if (isinput == true)
		{
			switch (msg.ch)
			{
			case '\b':		//删除
				if (!text.empty())
				{
					text.pop_back();
				}
				break;
			case '\r':		//换行
			case '\n':
				isinput = false;
				rect.Resetcolor();
				break;	
			default:		//其他字符
				text.push_back(msg.ch);
				break;	
			}
		}
		break;
	}
}

void Edit::SetInputType(int type)
{
	this->type = type;
}

wstring Edit::GetText()const
{
	return text;
}

wstring& Edit::GetText()
{
	return text;
}

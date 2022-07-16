#include <iostream>
#include <cstdlib>
#include "ccc.h"
using std::endl;
using std::cout;
using std::cin;

//画框框
void HuaTu::DrawKuang() const
{
	setfillcolor(color);
	solidrectangle(x, y, x + w, y + h);
}

//处理鼠标
bool HuaTu::MouseInK(MOUSEMSG msg)
{
	if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
	{

		return true;
	}
	return false;
}

/*
人的点击
*/

void Person::MouseLDown(MOUSEMSG msg, HuaTu(*prArray)[COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (prArray[i][j].MouseInK(msg) && msg.uMsg == WM_LBUTTONDOWN)
			{
				color = prArray[i][j].Color();
				setfillcolor(color);
				Circlefg = true;
			}
		}
	}
}

//默认画圆
void Person::DrawCircle(MOUSEMSG msg, HuaTu(*prArray)[COL])
{
	if (msg.y >= 160 && Circlefg && msg.uMsg == WM_LBUTTONDOWN)
	{
		solidcircle(msg.x, msg.y, 20);
		
	}
}

//选择画笔
void Person::DrawHuabi(MOUSEMSG msg)
{
	if (msg.x >= 380 && msg.x <= 420 && msg.y >= 10 && msg.y <= 40 && msg.uMsg == WM_LBUTTONDOWN)
	{
		clearrectangle(520, 10, 600, 40);
		outtextxy(520, 10, "自由画笔");
		Circlefg = false;
		int x0, y0;
		COLORREF color_temp;
		Linefg = true;
		setlinecolor(color);
		while (1)
		{
		flag:										//重置开始
			msg = GetMouseMsg();					// 获取一次鼠标消息
			color_temp = ChoiceInTool_Color(msg);	// 在工具内选择颜色
			setlinecolor(color_temp);
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				x0 = msg.x;
				y0 = msg.y;							//鼠标第一次按下时，得到开始坐标（x0,y0）
				Clear(msg);
				if (QuitChoice(msg))
				{
					Linefg = false;
					return;		//返回
				}
				while (1)
				{
					msg = GetMouseMsg();			// 获取一条鼠标消息
					BeginBatchDraw();
					if (msg.y >= 160)
					{
						line(x0, y0, msg.x, msg.y);
					}
					EndBatchDraw();

					x0 = msg.x;
					y0 = msg.y;		//更新坐标
					Clear(msg);
					if (QuitChoice(msg))
					{
						Linefg = false;
						return;		//返回
					}
					switch (msg.uMsg)
					{
					case WM_LBUTTONUP:
						goto flag;   //左键弹起  结束绘制 跳回到flag处进行重置
						break;
					}
				}
				break;
			}
		}
	}
		
}

//点击画直线  两点法
void Person::DrawLine(MOUSEMSG msg)
{
	if (msg.x >= 380 && msg.x <= 420 && msg.y >= 60 && msg.y <= 100 && msg.uMsg == WM_LBUTTONDOWN)
	{
		clearrectangle(520, 10, 600, 40);
		outtextxy(520, 10, "两点直线");
		int x0, y0, x1, y1;
		setlinecolor(color);
		while (1)
		{
		flag:						//重置开始
			msg = GetMouseMsg();	// 获取一次鼠标消息
			setlinecolor(ChoiceInTool_Color(msg));
			switch (msg.uMsg)		//判断鼠标信息类型
			{
			case WM_LBUTTONDOWN:
				x0 = msg.x;
				y0 = msg.y;			//鼠标第一次按下时，获取鼠标当前坐标（x0,y0）
				circle(x0, y0, 1);
				Clear(msg);
				if (QuitChoice(msg))
				{
					//随时退出
					return;
				}

				while (1)
				{
					msg = GetMouseMsg();// 再次获取一条鼠标消息
					switch (msg.uMsg)
					{
					case WM_LBUTTONDOWN:
						x1 =msg.x;
						y1 = msg.y;	//鼠标第二次按下时,得到坐标（x1,y1）
						cout << "画线" << endl;
						BeginBatchDraw();
						if (y1 >= 160 && y0>=160)
						{
							line(x0, y0, x1, y1);
						}
						setlinecolor(ChoiceInTool_Color(msg));

						Clear(msg);
						if (QuitChoice(msg))
						{
							//随时退出
							return;
						}
						EndBatchDraw();
						circle(x1, y1, 1);
						goto flag;   //跳回到flag处进行重置
					}
				}
			}
		}
	}
		 
}

//画椭圆
void Person::DrawEpic(MOUSEMSG msg)
{
	if (msg.x >= 450 && msg.x <= 490 && msg.y >= 60 && msg.y <= 100 && msg.uMsg == WM_LBUTTONDOWN)
	{
		clearrectangle(520, 10, 600, 40);
		outtextxy(520, 10, "拖拽椭圆");
		int x0, y0, x1, y1;
		setlinecolor(color);
#if 0
		while (1)
		{
		flag:						//重置开始
			msg = GetMouseMsg();	// 获取一次鼠标消息
			switch (msg.uMsg)		//判断鼠标信息类型
			{
			case WM_LBUTTONDOWN:	//鼠标点击 矩形起点
				x0 = msg.x;
				y0 = msg.y;
				msg = GetMouseMsg();
				while (1)
				{
					msg = GetMouseMsg();
					BeginBatchDraw();
					ellipse(x0, y0, msg.x, msg.y);	//鼠标的随即移动 矩形随时更新
					EndBatchDraw();
					cout << "拖动" << endl;
					switch (msg.uMsg)
					{
					case WM_LBUTTONUP:		//鼠标松开 矩形确定
						BeginBatchDraw();
						ellipse(x0, y0, msg.x, msg.y);	//鼠标的随即移动 矩形随时更新
						cout << "结束" << endl;
						EndBatchDraw();
						goto flag;
						break;
					}
					break;		
				}
				break;
			}
		}
#else
		while (1)
		{
		flag:						//重置开始
			msg = GetMouseMsg();		// 获取一次鼠标消息
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				x0 = msg.x;
				y0 = msg.y;			//鼠标第一次按下时，得到开始坐标（x0,y0）
				Clear(msg);
				if (QuitChoice(msg))
				{
					return;
				}
				while (1)
				{
					msg = GetMouseMsg();// 获取一条鼠标消息
					cout << "拖动" << endl;
					switch (msg.uMsg)
					{
					Clear(msg);
					if (QuitChoice(msg))
					{
						return;
					}
					case WM_LBUTTONUP:
						BeginBatchDraw();
						ellipse(x0, y0, msg.x, msg.y);
						EndBatchDraw();
						goto flag;   //左键弹起  结束绘制 跳回到flag处进行重置
						break;
					}
				}
				break;
			}
		}
#endif
	}
}

//画矩形
void Person::DrawRectangle(MOUSEMSG msg)
{
	if (msg.x >= 530 && msg.x <= 570 && msg.y >= 60 && msg.y <= 100 && msg.uMsg==WM_LBUTTONDOWN)
	{
		clearrectangle(520, 10, 600, 40);
		outtextxy(520, 10, "拖拽矩形");
		int x0, y0, x1, y1;
		setlinecolor(color);
		while (1)
		{
		flag:
			msg = GetMouseMsg();
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				x0 = msg.x;
				y0 = msg.y;
				Clear(msg);
				if (QuitChoice(msg))
				{
					return;
				}
				while (1)
				{
					msg = GetMouseMsg();
					Clear(msg);
					if (QuitChoice(msg))
					{
						return;
					}
					switch (msg.uMsg)
					{
					case WM_LBUTTONUP:
						BeginBatchDraw();
						rectangle(x0, y0, msg.x, msg.y);
						EndBatchDraw();
						goto flag;
						break;
					}
				}
				break;
			}
		}
	}
}

//在工具内选择颜色
COLORREF Person::ChoiceInTool_Color(MOUSEMSG msg, HuaTu(*prArray)[COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (prArray[i][j].MouseInK(msg) && msg.uMsg == WM_LBUTTONDOWN)
			{
				color = prArray[i][j].Color();
				return color;
			}
		}
	}
	return color;
}

//清空屏幕
void Person::Clear(MOUSEMSG msg)
{
	if (msg.x >= 750 && msg.x <= 780 && msg.y >= 110 && msg.y <= 150 && msg.uMsg == WM_LBUTTONDOWN)
	{
		//清空矩形区域
		clearrectangle(0, 160, getwidth(), getheight());
	}
}

//返回选择的窗口判断点击
bool Person::QuitChoice(MOUSEMSG msg)
{
	if (msg.x >= 700 && msg.x <= 780 && msg.y >= 10 && msg.y <= 40)
	{
		//取消选择
		return true;
	}
	return false;
}

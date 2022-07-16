#include <iostream>
#include <conio.h>
#include "ccc.h"
using std::cout;
using std::cin;
using std::endl;

void Draw(HuaTu(*prArray)[COL]);

#if 1
int main()
{
	initgraph(800, 640, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	COLORREF shuzu[ROW][COL] =
	{
		{GREEN,RGB(75,126,145),RED,BLACK,YELLOW,RGB(127,130,187),RGB(187,50,184),RGB(187,1,113)},
		{LIGHTBLUE,LIGHTGREEN,BROWN,LIGHTRED,RGB(150,62,95),RGB(58,187,0),RGB(187,0,0),RGB(187,97,0)},
		{RGB(153,217,234),RGB(162,167,234),RGB(234,139,232),RGB(212,234,86),RGB(94,234,202),RGB(182,176,187),RGB(187,136,137),RGB(187,133,133)},
		{RGB(213,58,234),RGB(234,196,94),RGB(234,164,164),RGB(6,190,234),RGB(2334,165,229),RGB(104,187,129),RGB(75,65,187),RGB(0,178,187)},

	};
	Person peo;

	int x = 10;
	int y = 10;
	int w = 30;
	int h = 30;
	int org_x = 0;
	int org_y = 0;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			colorK[i][j] = HuaTu(x, y, w, h, shuzu[i][j]);
			x += 40;
		}
		x = 10;
		y += 35;
	}
	MOUSEMSG msg;
	
	Draw(colorK);
	while (1)
	{

		msg = GetMouseMsg();			//接受鼠标消息

		BeginBatchDraw();
		peo.MouseLDown(msg);			//人的点击颜色确定
		peo.DrawCircle(msg);			//人的画圆		
		peo.DrawHuabi(msg);				//人的画笔
		peo.DrawLine(msg);				//人的画直线
		peo.DrawEpic(msg);				//人的画椭圆
		peo.DrawRectangle(msg);			//人的画矩形
		peo.Clear(msg);					//人的清空屏幕

		EndBatchDraw();


		if (peo.ShowEvent())
		{
			outtextxy(520, 10, "点击画圆");
		}
	}





	system("pause");
	return 0;
}
void Draw(HuaTu(*prArray)[COL])
{
	//line(392, 59, 440, 109);
	setfillcolor(LIGHTGRAY);
	fillrectangle(0, 0, getwidth(), 150);

	setfillcolor(WHITE);
	//提示直线框
	fillrectangle(380, 60, 420, 100);
	//提示椭圆
	fillrectangle(450, 60, 490, 100);
	//提示矩形框
	fillrectangle(530, 60, 570, 100);

	//提示画笔
	settextcolor(GREEN);
	settextstyle(30, 0, "微软雅黑");
	fillrectangle(380, 10, 420, 40);
	outtextxy(380, 10, "画笔");
	//当前提示框
	fillrectangle(450, 10, 600, 40);
	outtextxy(450, 10, "当前:");
	//退出提示框
	fillrectangle(700, 10, 780, 40);
	outtextxy(700, 10, "选择工具");

	//直线
	setlinecolor(BLACK);
	line(390, 80, 410, 80);
	//椭圆
	ellipse(455, 70, 485, 90);
	//矩形
	rectangle(535, 75, 565, 85);
	//清空
	outtextxy(750, 110, "清空");
	//分割线
	solidrectangle(0, 150, getwidth(), 155);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			prArray[i][j].DrawKuang();
		}
	}
}


#else
void pen()
{
	int x0, y0;
	MOUSEMSG msg;				// 定义鼠标消息
	setlinecolor(RED);
	while (1)
	{
	flag:						//重置开始
		msg = GetMouseMsg();		// 获取一次鼠标消息
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			x0 = msg.x; 
			y0 = msg.y;			//鼠标第一次按下时，得到开始坐标（x0,y0）
			while (1)
			{
				msg = GetMouseMsg();// 获取一条鼠标消息
				line(x0, y0, msg.x, msg.y);
				x0 = msg.x;
				y0 = msg.y;		//更新坐标
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
struct oio
{
	COLORREF color = RED;
}a;
COLORREF color()
{
	a.color = GREEN;
	return a.color;
}
void main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	MOUSEMSG m;
	setfillcolor(color());
	while (1)
	{
		fillrectangle(50, 50, 200, 200);
	}
}


#endif
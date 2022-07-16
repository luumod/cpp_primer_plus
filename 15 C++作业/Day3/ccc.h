

#ifndef CCC_H_
#define CC_H_H
#include <graphics.h>
#include <string>
using std::string;


const int ROW = 4;
const int COL = 8;

class HuaTu
{
private:
	int x;							//每个小框的X坐标
	int y;							//每个小框的Y坐标
	int w;							//每个小框的宽度
	int h;							//每个小框的高度
	COLORREF color;					//当前对象的颜色
	COLORREF now_color = WHITE;		//作画的颜色
protected:
	//传给作画人当前颜色
public:
	//默认构造函数
	HuaTu(int X = 100, int Y = 100, int W = 50, int H = 50, COLORREF col = RED, COLORREF now_col=WHITE)
		:x(X), y(Y), w(W), h(H), color(col), now_color(now_col) {}
	//画框框
	void DrawKuang()const;
	//处理鼠标
	bool MouseInK(MOUSEMSG msg);
	//画线
	
	COLORREF Show_Now_color()const
	{
		return now_color;
	}
	//当前对象颜色
	COLORREF Color()const
	{
		return color;
	}
};

static HuaTu colorK[ROW][COL];

class Person : public HuaTu
{
private:
	bool Circlefg = true; 
	bool Linefg = false;
	COLORREF color = BLACK;
public:
	//鼠标是否位于选色框内
	void MouseLDown(MOUSEMSG msg, HuaTu(*prArray)[COL] = colorK);
	//点击画圆
	void DrawCircle(MOUSEMSG msg, HuaTu(*prArray)[COL] = colorK);
	//鼠标点击画笔
	void DrawHuabi(MOUSEMSG msg);
	//鼠标点击画直线
	void DrawLine(MOUSEMSG msg);
	//鼠标点击画椭圆
	void DrawEpic(MOUSEMSG msg);
	//鼠标点击画矩形
	void DrawRectangle(MOUSEMSG msg);
	//选择颜色
	COLORREF ChoiceInTool_Color(MOUSEMSG msg, HuaTu(*prArray)[COL]=colorK);
	//清空屏幕
	void Clear(MOUSEMSG msg);
	//重新选择
	bool QuitChoice(MOUSEMSG msg);
	//显示当前事件
	bool ShowEvent()const
	{
		return Circlefg;
	}
	//返回标记
	bool ReturnLinefg()const
	{
		return Linefg;
	}
};
#endif
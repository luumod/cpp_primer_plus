

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
	int x;							//ÿ��С���X����
	int y;							//ÿ��С���Y����
	int w;							//ÿ��С��Ŀ��
	int h;							//ÿ��С��ĸ߶�
	COLORREF color;					//��ǰ�������ɫ
	COLORREF now_color = WHITE;		//��������ɫ
protected:
	//���������˵�ǰ��ɫ
public:
	//Ĭ�Ϲ��캯��
	HuaTu(int X = 100, int Y = 100, int W = 50, int H = 50, COLORREF col = RED, COLORREF now_col=WHITE)
		:x(X), y(Y), w(W), h(H), color(col), now_color(now_col) {}
	//�����
	void DrawKuang()const;
	//�������
	bool MouseInK(MOUSEMSG msg);
	//����
	
	COLORREF Show_Now_color()const
	{
		return now_color;
	}
	//��ǰ������ɫ
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
	//����Ƿ�λ��ѡɫ����
	void MouseLDown(MOUSEMSG msg, HuaTu(*prArray)[COL] = colorK);
	//�����Բ
	void DrawCircle(MOUSEMSG msg, HuaTu(*prArray)[COL] = colorK);
	//���������
	void DrawHuabi(MOUSEMSG msg);
	//�������ֱ��
	void DrawLine(MOUSEMSG msg);
	//���������Բ
	void DrawEpic(MOUSEMSG msg);
	//�����������
	void DrawRectangle(MOUSEMSG msg);
	//ѡ����ɫ
	COLORREF ChoiceInTool_Color(MOUSEMSG msg, HuaTu(*prArray)[COL]=colorK);
	//�����Ļ
	void Clear(MOUSEMSG msg);
	//����ѡ��
	bool QuitChoice(MOUSEMSG msg);
	//��ʾ��ǰ�¼�
	bool ShowEvent()const
	{
		return Circlefg;
	}
	//���ر��
	bool ReturnLinefg()const
	{
		return Linefg;
	}
};
#endif
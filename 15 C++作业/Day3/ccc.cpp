#include <iostream>
#include <cstdlib>
#include "ccc.h"
using std::endl;
using std::cout;
using std::cin;

//�����
void HuaTu::DrawKuang() const
{
	setfillcolor(color);
	solidrectangle(x, y, x + w, y + h);
}

//�������
bool HuaTu::MouseInK(MOUSEMSG msg)
{
	if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
	{

		return true;
	}
	return false;
}

/*
�˵ĵ��
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

//Ĭ�ϻ�Բ
void Person::DrawCircle(MOUSEMSG msg, HuaTu(*prArray)[COL])
{
	if (msg.y >= 160 && Circlefg && msg.uMsg == WM_LBUTTONDOWN)
	{
		solidcircle(msg.x, msg.y, 20);
		
	}
}

//ѡ�񻭱�
void Person::DrawHuabi(MOUSEMSG msg)
{
	if (msg.x >= 380 && msg.x <= 420 && msg.y >= 10 && msg.y <= 40 && msg.uMsg == WM_LBUTTONDOWN)
	{
		clearrectangle(520, 10, 600, 40);
		outtextxy(520, 10, "���ɻ���");
		Circlefg = false;
		int x0, y0;
		COLORREF color_temp;
		Linefg = true;
		setlinecolor(color);
		while (1)
		{
		flag:										//���ÿ�ʼ
			msg = GetMouseMsg();					// ��ȡһ�������Ϣ
			color_temp = ChoiceInTool_Color(msg);	// �ڹ�����ѡ����ɫ
			setlinecolor(color_temp);
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				x0 = msg.x;
				y0 = msg.y;							//����һ�ΰ���ʱ���õ���ʼ���꣨x0,y0��
				Clear(msg);
				if (QuitChoice(msg))
				{
					Linefg = false;
					return;		//����
				}
				while (1)
				{
					msg = GetMouseMsg();			// ��ȡһ�������Ϣ
					BeginBatchDraw();
					if (msg.y >= 160)
					{
						line(x0, y0, msg.x, msg.y);
					}
					EndBatchDraw();

					x0 = msg.x;
					y0 = msg.y;		//��������
					Clear(msg);
					if (QuitChoice(msg))
					{
						Linefg = false;
						return;		//����
					}
					switch (msg.uMsg)
					{
					case WM_LBUTTONUP:
						goto flag;   //�������  �������� ���ص�flag����������
						break;
					}
				}
				break;
			}
		}
	}
		
}

//�����ֱ��  ���㷨
void Person::DrawLine(MOUSEMSG msg)
{
	if (msg.x >= 380 && msg.x <= 420 && msg.y >= 60 && msg.y <= 100 && msg.uMsg == WM_LBUTTONDOWN)
	{
		clearrectangle(520, 10, 600, 40);
		outtextxy(520, 10, "����ֱ��");
		int x0, y0, x1, y1;
		setlinecolor(color);
		while (1)
		{
		flag:						//���ÿ�ʼ
			msg = GetMouseMsg();	// ��ȡһ�������Ϣ
			setlinecolor(ChoiceInTool_Color(msg));
			switch (msg.uMsg)		//�ж������Ϣ����
			{
			case WM_LBUTTONDOWN:
				x0 = msg.x;
				y0 = msg.y;			//����һ�ΰ���ʱ����ȡ��굱ǰ���꣨x0,y0��
				circle(x0, y0, 1);
				Clear(msg);
				if (QuitChoice(msg))
				{
					//��ʱ�˳�
					return;
				}

				while (1)
				{
					msg = GetMouseMsg();// �ٴλ�ȡһ�������Ϣ
					switch (msg.uMsg)
					{
					case WM_LBUTTONDOWN:
						x1 =msg.x;
						y1 = msg.y;	//���ڶ��ΰ���ʱ,�õ����꣨x1,y1��
						cout << "����" << endl;
						BeginBatchDraw();
						if (y1 >= 160 && y0>=160)
						{
							line(x0, y0, x1, y1);
						}
						setlinecolor(ChoiceInTool_Color(msg));

						Clear(msg);
						if (QuitChoice(msg))
						{
							//��ʱ�˳�
							return;
						}
						EndBatchDraw();
						circle(x1, y1, 1);
						goto flag;   //���ص�flag����������
					}
				}
			}
		}
	}
		 
}

//����Բ
void Person::DrawEpic(MOUSEMSG msg)
{
	if (msg.x >= 450 && msg.x <= 490 && msg.y >= 60 && msg.y <= 100 && msg.uMsg == WM_LBUTTONDOWN)
	{
		clearrectangle(520, 10, 600, 40);
		outtextxy(520, 10, "��ק��Բ");
		int x0, y0, x1, y1;
		setlinecolor(color);
#if 0
		while (1)
		{
		flag:						//���ÿ�ʼ
			msg = GetMouseMsg();	// ��ȡһ�������Ϣ
			switch (msg.uMsg)		//�ж������Ϣ����
			{
			case WM_LBUTTONDOWN:	//����� �������
				x0 = msg.x;
				y0 = msg.y;
				msg = GetMouseMsg();
				while (1)
				{
					msg = GetMouseMsg();
					BeginBatchDraw();
					ellipse(x0, y0, msg.x, msg.y);	//�����漴�ƶ� ������ʱ����
					EndBatchDraw();
					cout << "�϶�" << endl;
					switch (msg.uMsg)
					{
					case WM_LBUTTONUP:		//����ɿ� ����ȷ��
						BeginBatchDraw();
						ellipse(x0, y0, msg.x, msg.y);	//�����漴�ƶ� ������ʱ����
						cout << "����" << endl;
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
		flag:						//���ÿ�ʼ
			msg = GetMouseMsg();		// ��ȡһ�������Ϣ
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				x0 = msg.x;
				y0 = msg.y;			//����һ�ΰ���ʱ���õ���ʼ���꣨x0,y0��
				Clear(msg);
				if (QuitChoice(msg))
				{
					return;
				}
				while (1)
				{
					msg = GetMouseMsg();// ��ȡһ�������Ϣ
					cout << "�϶�" << endl;
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
						goto flag;   //�������  �������� ���ص�flag����������
						break;
					}
				}
				break;
			}
		}
#endif
	}
}

//������
void Person::DrawRectangle(MOUSEMSG msg)
{
	if (msg.x >= 530 && msg.x <= 570 && msg.y >= 60 && msg.y <= 100 && msg.uMsg==WM_LBUTTONDOWN)
	{
		clearrectangle(520, 10, 600, 40);
		outtextxy(520, 10, "��ק����");
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

//�ڹ�����ѡ����ɫ
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

//�����Ļ
void Person::Clear(MOUSEMSG msg)
{
	if (msg.x >= 750 && msg.x <= 780 && msg.y >= 110 && msg.y <= 150 && msg.uMsg == WM_LBUTTONDOWN)
	{
		//��վ�������
		clearrectangle(0, 160, getwidth(), getheight());
	}
}

//����ѡ��Ĵ����жϵ��
bool Person::QuitChoice(MOUSEMSG msg)
{
	if (msg.x >= 700 && msg.x <= 780 && msg.y >= 10 && msg.y <= 40)
	{
		//ȡ��ѡ��
		return true;
	}
	return false;
}

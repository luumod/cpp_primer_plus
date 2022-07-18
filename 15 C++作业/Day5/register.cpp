#pragma once
#include "register.h"
#include "edit.h"
#include "button.h"
#include "Label.h"

Register::Register()
{
	HWND hwnd;
	hwnd = initgraph(400, 300, SHOWCONSOLE);
	setbkcolor(LIGHTBLUE);
	cleardevice();

	edit1 = new Edit{ 150,80,200,30 };		//ע���˺�
	edit2 = new Edit{ 150,130, 200, 30 };		//ע������
	edit3 = new Edit{ 150,180,200,30 };		//ע������
	edit2->SetInputType(Edit::EDIT::jiami);		//�����������
	edit3->SetInputType(Edit::EDIT::jiami);		//�����������


	lab1 = new Label{ L"  �˺�:" };
	lab2 = new Label{ L"  ����:" };
	lab3 = new Label{ L"ȷ������:" };

	button1 = new Button{ 200,240,100,50,WHITE,L"ȷ��" };

	lab4 = new Label{ L"ע���˺�" };
	lab4->SetLabelstyle(BLUE, 30, L"΢���ź�");
	lab4->Draw((getwidth() - textwidth(lab4->Gettext().c_str())) / 2, 20);
	
	Show();
	OnEvent();
}

Register::~Register()
{
	delete edit1;
	delete edit2;
	delete edit3;
	delete lab1;
	delete lab2;
	delete lab3;
	delete lab4;
	delete button1;

	//closegraph();
}

void Register::Show()
{
	edit1->TextDraw();
	edit2->TextDraw();
	edit3->TextDraw();
	lab1->Draw(30, 80);
	lab2->Draw(30, 130);
	lab3->Draw(30, 180);
	button1->Draw();
}



void Register::OnEvent()
{
	ExMessage msg;
	BeginBatchDraw();
	while (1)
	{
		while (peekmessage(&msg))
		{
			edit1->OnEvent(msg);
			edit2->OnEvent(msg);
			edit3->OnEvent(msg);
			button1->MouseInButton(msg);
			if (button1->ClickButton(msg))
			{
				if (edit2->GetText() == edit3->GetText())
				{
					//���ȷ��   ����Ҫ��������������һ��
					account = edit1->GetText();
					password = edit2->GetText();
					MessageBox(hwnd, L"ע��ɹ�", L"��ʾ", MB_OK);
					return;
				}
				else
				{
					int result = 0;
					//�������벻һ��
					result = MessageBox(hwnd, L"�����������벻һ��", L"����", MB_YESNO);
					if (result == IDYES)
					{
						//ȷ����������
						while (!edit2->GetText().empty())
						{
							edit2->GetText().pop_back();
						}
						while (!edit3->GetText().empty())
						{
							edit3->GetText().pop_back();
						}

					}
					else if (result == IDNO)
					{
						//ֱ���˳�
						return;
					}
				}
			}
		}
		Show();
		FlushBatchDraw();
	}
	EndBatchDraw();
}

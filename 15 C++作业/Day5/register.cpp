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

	edit1 = new Edit{ 150,80,200,30 };		//注册账号
	edit2 = new Edit{ 150,130, 200, 30 };		//注册密码
	edit3 = new Edit{ 150,180,200,30 };		//注册密码
	edit2->SetInputType(Edit::EDIT::jiami);		//密码加密输入
	edit3->SetInputType(Edit::EDIT::jiami);		//密码加密输入


	lab1 = new Label{ L"  账号:" };
	lab2 = new Label{ L"  密码:" };
	lab3 = new Label{ L"确认密码:" };

	button1 = new Button{ 200,240,100,50,WHITE,L"确认" };

	lab4 = new Label{ L"注册账号" };
	lab4->SetLabelstyle(BLUE, 30, L"微软雅黑");
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
					//点击确定   并且要求两次密码输入一致
					account = edit1->GetText();
					password = edit2->GetText();
					MessageBox(hwnd, L"注册成功", L"提示", MB_OK);
					return;
				}
				else
				{
					int result = 0;
					//密码输入不一致
					result = MessageBox(hwnd, L"两次密码输入不一致", L"警告", MB_YESNO);
					if (result == IDYES)
					{
						//确定重新输入
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
						//直接退出
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

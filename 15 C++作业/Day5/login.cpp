#include "login.h"
#include "register.h"
/*
包含所需的头文件
*/
#include "edit.h"
#include "Label.h"
#include "button.h"

Login::Login()
{
	/*
	默认账号密码
	*/
	account = L"1173012900";
	password = L"123456789";
	hwnd = initgraph(400, 300, SHOWCONSOLE);
	setbkcolor(LIGHTGRAY);
	cleardevice();

	pUserAccount= new Edit{ 100,80,200,30 };			//登录账号
	pUserSercrt=new Edit{ 100,130, 200, 30 };

	pUserAccount_Label = new Label{ L"账号:" };
	pUserSercrt_Label = new Label{ L"密码:" };
	pUserSercrt->SetInputType(Edit::EDIT::jiami);		//密码输入方式
	pUserDenglubiaoti = new Label{ L"登陆系统" };

	Login_Button = new Button{ 200,200,100,50,WHITE,L"登录" };
	Login_Zhuce = new Button{ 50,200,100,50,WHITE,L"注册" };

	pUserDenglubiaoti->SetLabelstyle(BLUE, 30, L"微软雅黑");

	Show();
	OnEvent();
}

Login::~Login()
{
	delete pUserAccount;
	delete pUserSercrt;
	delete pUserAccount_Label;
	delete pUserSercrt_Label;
	delete pUserDenglubiaoti;
	delete Login_Button;
	delete Login_Zhuce;

	closegraph();
}

void Login::Show()
{
	/*
	把所有的绘制写在一个绘制函数中
	*/
	pUserAccount->TextDraw();
	pUserSercrt->TextDraw();
	pUserAccount_Label->Draw(20,80);
	pUserSercrt_Label->Draw(20, 130);
	Login_Button->Draw();
	Login_Zhuce->Draw();
	pUserDenglubiaoti->Draw((getwidth() - textwidth(pUserDenglubiaoti->Gettext().c_str())) / 2, 20);
}

void Login::OnEvent()
{
	ExMessage msg;
	BeginBatchDraw();
	while (1)
	{
		while (peekmessage(&msg))
		{
			pUserAccount->OnEvent(msg);
			pUserSercrt->OnEvent(msg);

			Login_Button->MouseInButton(msg);
			Login_Zhuce->MouseInButton(msg);
			if (Login_Button->ClickButton(msg))
			{
				/*
				登录
				*/
				if (pUserAccount->GetText() == account && pUserSercrt->GetText() == password)
				{
					MessageBox(hwnd, L"登陆成功", L"提示", MB_OK);
					return;
				}
				else
				{
					int i = 0;
					i = MessageBox(hwnd, L"密码错误", L"提示", MB_YESNO);
					if (i == IDYES)
					{
						/*
						重新输入
						*/
						while (!pUserSercrt->GetText().empty())
						{
							pUserSercrt->GetText().pop_back();
						}
					}
					else if (i==IDNO)
					{
						return;
					}
					
				}
			}
			if (Login_Zhuce->ClickButton(msg))
			{
				/*
				注册
				*/
				Register m;
				this->account = m.Getaccount();
				this->password = m.Getpassword();
				cleardevice();
			}
		}
		Show();
		FlushBatchDraw();
	}
	EndBatchDraw();
}

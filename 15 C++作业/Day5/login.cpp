#include "login.h"
#include "register.h"
/*
���������ͷ�ļ�
*/
#include "edit.h"
#include "Label.h"
#include "button.h"

Login::Login()
{
	/*
	Ĭ���˺�����
	*/
	account = L"1173012900";
	password = L"123456789";
	hwnd = initgraph(400, 300, SHOWCONSOLE);
	setbkcolor(LIGHTGRAY);
	cleardevice();

	pUserAccount= new Edit{ 100,80,200,30 };			//��¼�˺�
	pUserSercrt=new Edit{ 100,130, 200, 30 };

	pUserAccount_Label = new Label{ L"�˺�:" };
	pUserSercrt_Label = new Label{ L"����:" };
	pUserSercrt->SetInputType(Edit::EDIT::jiami);		//�������뷽ʽ
	pUserDenglubiaoti = new Label{ L"��½ϵͳ" };

	Login_Button = new Button{ 200,200,100,50,WHITE,L"��¼" };
	Login_Zhuce = new Button{ 50,200,100,50,WHITE,L"ע��" };

	pUserDenglubiaoti->SetLabelstyle(BLUE, 30, L"΢���ź�");

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
	�����еĻ���д��һ�����ƺ�����
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
				��¼
				*/
				if (pUserAccount->GetText() == account && pUserSercrt->GetText() == password)
				{
					MessageBox(hwnd, L"��½�ɹ�", L"��ʾ", MB_OK);
					return;
				}
				else
				{
					int i = 0;
					i = MessageBox(hwnd, L"�������", L"��ʾ", MB_YESNO);
					if (i == IDYES)
					{
						/*
						��������
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
				ע��
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

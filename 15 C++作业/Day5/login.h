#pragma once
#include "common.h"


class Edit;
class Label;
class Rect;
class Button;
/*
��¼����
*/
class Login
{
private:
	wstring account;
	wstring password;
	/*
	�༭
	*/
	Edit* pUserAccount;			//�˺�
	Edit* pUserSercrt;			//����
	/*
	��ǩ
	*/
	Label* pUserAccount_Label;		//��ʾ�˺�����
	Label* pUserSercrt_Label;		//��ʾ��������
	Label* pUserDenglubiaoti;		//��¼ϵͳ����
	/*
	��ť
	*/
	Button* Login_Button;			//��¼
	Button* Login_Zhuce;			//ע��

	HWND hwnd;
public:
	Login();
	~Login();
	void Show();
	void OnEvent();
};
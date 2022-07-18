#pragma once
#include "common.h"


class Edit;
class Label;
class Rect;
class Button;
/*
登录窗口
*/
class Login
{
private:
	wstring account;
	wstring password;
	/*
	编辑
	*/
	Edit* pUserAccount;			//账号
	Edit* pUserSercrt;			//密码
	/*
	标签
	*/
	Label* pUserAccount_Label;		//提示账号输入
	Label* pUserSercrt_Label;		//提示密码输入
	Label* pUserDenglubiaoti;		//登录系统标题
	/*
	按钮
	*/
	Button* Login_Button;			//登录
	Button* Login_Zhuce;			//注册

	HWND hwnd;
public:
	Login();
	~Login();
	void Show();
	void OnEvent();
};
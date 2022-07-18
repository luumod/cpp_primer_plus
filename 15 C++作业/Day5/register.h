#pragma once
#include "common.h"

class Edit;
class Label;
class Button;

class Register
{
private:
	HWND hwnd;
	wstring account;
	wstring password;

	Edit* edit1;
	Edit* edit2;
	Edit* edit3;

	Label* lab1;
	Label* lab2;
	Label* lab3;
	Label* lab4;

	Button* button1;

public:
	Register();
	~Register();

	void Show();
	void OnEvent();
	wstring Getaccount()const
	{
		return account;
	}
	wstring Getpassword()const
	{
		return password;
	}
};
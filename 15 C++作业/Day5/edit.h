#pragma once
#include "common.h"
#include "rect.h"
#include "curcos.h"

/*
编辑框
*/
class Edit
{
public:
	enum EDIT { jiami, jiemi };
private:
	Rect rect;				//矩形输入框
	std::wstring text;		//宽字符
	Curcos pos;				//光标
	bool isinput;			//是否处于输入状态标记
	int textw;				//文字宽度
	int type;				//输入方式
public:
	Edit(int x, int y, int w, int h);
	void TextDraw();
	bool MouseInEdit(ExMessage msg);
	void OnEvent(ExMessage msg);
	void SetInputType(int type);
	wstring GetText()const ;
	wstring& GetText();
};
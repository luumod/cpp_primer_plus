#pragma once

#include "common.h"

/*
���ֱ�ǩ
*/
class Label
{
private:
	wstring text;		//����
	COLORREF color;		//��ɫ
	int textw;			//���ֿ��
	wstring style;		//������ʽ
public:
	Label(wstring text);
	void SetLabelstyle(COLORREF color, int textw, wstring tyle);
	void Draw(int x,int y);
	wstring Gettext();
};

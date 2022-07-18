#pragma once
#include "common.h"
#include "rect.h"
#include "curcos.h"

/*
�༭��
*/
class Edit
{
public:
	enum EDIT { jiami, jiemi };
private:
	Rect rect;				//���������
	std::wstring text;		//���ַ�
	Curcos pos;				//���
	bool isinput;			//�Ƿ�������״̬���
	int textw;				//���ֿ��
	int type;				//���뷽ʽ
public:
	Edit(int x, int y, int w, int h);
	void TextDraw();
	bool MouseInEdit(ExMessage msg);
	void OnEvent(ExMessage msg);
	void SetInputType(int type);
	wstring GetText()const ;
	wstring& GetText();
};
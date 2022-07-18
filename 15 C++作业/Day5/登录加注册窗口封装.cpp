


#if 1


#include "login.h"

int main()
{
	/*
	登录模块
	*/
	Login w;

	/*
	放其他东西
	*/

	//system("pause");
	return 0;
}



#elif  0
#include "Label.h"
int main()
{
	initgraph(400, 300);
	setbkcolor(WHITE);
	cleardevice();
	Label* l = new Label(L"账号:");
	Label* m = new Label(L"密码:");

	l->Draw(100,111);
	m->Draw(100,222);
	while (1);
	return 0;
}


#endif
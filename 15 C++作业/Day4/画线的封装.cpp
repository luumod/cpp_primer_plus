
#include "line.h"
using namespace std;

#if 1
int main()
{
	initgraph(800, 600,SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	ExMessage msg;
	Line* pline = new Line(5, BLACK);

	while (1)
	{
		while (peekmessage(&msg))
		{
			pline->WScontrolLineStyle();		//w s �����ߵĴ�ϸ
			pline->MouseDrawLine(msg);			//����
		}
	}

	return 0;
}
#else

int main()
{
	initgraph(800, 600,SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	ExMessage msg;
	WPARAM wParam=0;
	int  zoom = 0;
	DWORD dwData = 0;
	while (1)
	{
		mouse_event(0, 0, 0, dwData, 0);
		cout << dwData << endl;
	}
	return 0;
}

#endif
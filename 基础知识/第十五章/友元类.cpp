#include <iostream>
#include <string>
#include "tv友元类.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
/*
友元类
*/
#if 0
int main()
{
	Tv s42;
	cout << "初始化电视机信息: " << endl;
	s42.settings();
	s42.onoff();
	s42.chanup();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV: \n"; 
	s42.settings();

	Remote grey;

	grey.set_chan(s42,10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote : \n";
	s42.settings();

	Tv s58(Tv::ON); 
	s58.set_mode();

	grey.set_chan(s58, 28);
	cout << "\n58\" settings : \n";
	s58.settings();
	return 0;
}

#endif

/*
模板的嵌套
*/

#if 1
int main()
{
	/*QueueTP<int> one(10);
	int temp;

	for (int i = 0; i < 10; i++)
	{
		one.enqueue(i);
	}
	while (!one.isempty())
	{
		one.delqueue(temp);
		cout << temp << " ";
	}
	cout << "Bye!" << endl;*/
	QueueTP<string> cs(5);	//默认构造
	string temp;

	while (!cs.isfull())
	{
		cout << "请输入字符串: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "The queue is full! " << endl;
	while (!cs.isempty())
	{
		cs.delqueue(temp);
		cout << temp << endl;
	}
	return 0;
}

#endif

#include <iostream>
#include "公有继承与虚基类.h"
using std::cout;
using std::cin;
using std::endl;


/*
多重继承  抽象基类
*/
#if 0
Worker::~Worker()
{}

void Worker::Set()
{
	cout << "请输入工人名字: ";
	getline(cin, fullname);
	cout << "请输入工人ID: ";
	cin >> id;
	while (cin.get() != '\n')
		;
}

void Worker::Show() const
{
	cout << "Name: " << fullname << endl;
	cout << "ID: " << id << endl;
}

//派生类
void Waiter::Set()
{
	Worker::Set();	//设置基类成员部分
	cout << "请输入作者的评级分数: ";
	cin >> panache;
	while (cin.get() != '\n')
		;
}

void Waiter::Show() const
{
	cout << "作家信息: " << endl;
	Worker::Show();
	cout << "评分: " << panache << endl;
}


void Singer::Set()
{
	Worker::Set();
	cout << "输入的歌手的音色个数: ";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "超出限制!" << endl;
	while (cin.get() != '\n')
		;
}
void Singer::Show()const
{
	cout << "歌手信息: ";
	Worker::Show();
	cout << "音乐： " << pv[voice] << endl;
}
#endif



/*
虚基类
*/
#if 1  
Worker::~Worker()
{}

void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "请输入工人ID: ";
	cin >> id;
	while (cin.get() != '\n')
		;
}


//作家
void Waiter::Set()
{
	cout << "请输入作家信息: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "作家信息: " << endl;
	Worker::Data();
	Data();
}

void Waiter::Data() const
{
	cout << "评分: " << panache << endl;
}

void Waiter::Get()
{
	cout << "输入作家评分: ";
	cin >> panache;
	while (cin.get() != '\n')
		;
}

//音乐家
void Singer::Set()
{
	cout << "输入歌手信息: ";
	Worker::Get();
	Get();
}

void Singer::Show()const
{
	cout << "歌手信息: " << endl;
	Worker::Data();
	Data();
}

void Singer::Data()const
{
	cout << "音色: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "输入的歌手的音色: ";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "超出限制!" << endl;
	while (cin.get() != '\n')
		;
}

//音乐作家
void SingerWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}

void SingerWaiter::Get()
{
	Singer::Get();
	Waiter::Get();
}

void SingerWaiter::Set()
{
	cout << "请输入音乐作家的信息: ";
	Worker::Get();
	Get();
}

void SingerWaiter::Show()const
{
	cout << "音乐作家的信息: ";
	Worker::Data();
	Data();
}

#endif
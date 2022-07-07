

#include <iostream>
#include <string>
#include "抽象基类.h"

const int CLIENTS = 4;
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	//指针数组 来表示多态性
	AcctABC* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "请输入顾客名称: ";
		getline(cin, temp);
		cout << "请输入账号: ";
		cin >> tempnum;
		cout << "请输入余额: ";
		cin >> tempbal;
		cout << "请输入 1 进入基类银行; 2 进入派生类银行 ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			;
		if (kind == '1')
		{
			//创建派生类
			p_clients[i] = new Brass(temp, tempnum, tempbal);		//(temp, tempnum, tempbal)
		}
		else
		{
			double tempmax, temprate;
			cout << "请输入最大借款金额: ";
			cin >> tempmax;
			cout << "请输入借款利率: ";
			cin >> temprate;
			//创建派生类
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tempmax, temprate);
		}
		while (cin.get() != '\n')
			;
	}
	cout << "\n";
	/*
	多态性:
		如果数组成员是Brass  调用Brass::ViewAcct方法
		如果数组成员是BrassPlus  调用BrassPlus::ViewAcct方法
	*/
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	cout << "Done! " << endl;
	return 0;
}

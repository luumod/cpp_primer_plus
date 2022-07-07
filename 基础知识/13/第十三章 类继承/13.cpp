#include <iostream>
//#include "tabtan.h"
#include "抽象基类.h"
using std::cout;
using std::cin;
using std::endl;

//基类  普通继承
#if 0
int main()
{
	/*using std::cout;
	TablenTennusPlay Play1{ "chuck","wodjf",true };
	TablenTennusPlay Play2{ "aewef","okkksof",false };
	Play1.Name();
	if (Play1.HasTable())
	{
		cout << ": has a table,\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
	Play2.Name();
	if (Play2.HasTable())
	{
		cout << ": has a table,\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}*/



	return 0;
}
#endif

#if 0
void Show(const TablenTennusPlay& t);
//派生类
int main()
{
	using std::cout;
	TablenTennusPlay Play1{ "chuck","wodjf",true };
	TablenTennusPlay Play2{ "aewef","okkksof",false };
	RatedPlay rplayer1{ 111,"派生类","嘿嘿嘿",true };

	/*
	基类引用和指针都可以在不进行显式类型转换的情况下指向派生类对象
	但只能用于调用基类方法  不能用来调用派生类的方法
	反之则不能用派生类的指针和引用指向基类
	*/
	TablenTennusPlay* p = &rplayer1;
	TablenTennusPlay& q = rplayer1;
	Play1.Name();
	if (Play1.HasTable())
	{
		cout << ": has a table,\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
	rplayer1.Name();
	if (rplayer1.HasTable())
	{
		cout << ": has a table,\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
	RatedPlay rplayer2{ rplayer1 };
	rplayer2.Name();
	cout << rplayer2.Rating() << std::endl;

	rplayer1.ResetRating(99);
	Play1.ResetTable(9199);
	cout << rplayer1.HasTable() << endl;
	Show(Play1);
	Show(rplayer1);

	return 0;
}
void Show(const TablenTennusPlay& t)
{
	cout << t.HasTable() << endl;
}
#endif

/*
多态公有继承: 同一个方法在基类和派生类中行为不同
	在派生类中重新定义基类的方法
	使用虚方法
*/


//多态继承
/*
银行贷款
*/
#if 0
int main()
{
	Brass Piggy{ "Piggy",300000,4000 };
	//此处调用了派生类第一个构造函数
	//三个参数创建一个基类对象  剩余默认参数为派生类对象属性
	BrassPlus Hoggy{ "Hoggy",33200,3500};	
	//BrassPlus Hoggy{ "Hoggy",331000,3500 };
	//显示账户信息
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;

	cout << "向Hoggy账户存入1000美元。\n";
	Hoggy.Deposit(1000);
	cout << "您的余额 : $ " << Hoggy.Balance() << endl;
	cout << "从Piggy账户中取出3800美元:\n";
	Piggy.WithDraw(3800);
	cout << "Piggy帐户余额: $" << Piggy.Balance() << endl;
	cout << "从Hoggy账户取4200美元:\n";
	Hoggy.WithDraw(4200);
	Hoggy.ViewAcct();

	return 0;
}
#endif

/*
显示虚方法的行为
*/

#if  0

const int CLIENTS = 4;
int main()
{
	//指针数组 来表示多态性
	Brass* p_clients[CLIENTS];
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
			//创建基类
			p_clients[i] = new Brass{ temp,tempnum,tempbal };
		}
		else
		{
			double tempmax, temprate;
			cout << "请输入最大借款金额: ";
			cin >> tempmax;
			cout << "请输入借款利率: ";
			cin >> temprate;
			//创建派生类
			p_clients[i] = new BrassPlus{ temp,tempnum,tempbal,tempmax,temprate };
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
#endif //  0

/*
静态联编
动态联编
*/

/*
向上强制转换
向下强制转换
*/

/*
虚成员函数适用于动态联编
*/

/*
1. 构造函数不能定义为虚函数
2. 析构函数在动态联编中应该定义为虚函数  在基类
3. 友元函数不是类成员 因此不能设置为虚的
4. 不能重新定义虚函数 否则旧的将会被隐藏 不会实现重载
	1. 在派生类中重新定义虚函数的话，只允许返回类型发生变化 如由返回基类引用或指针变为指向派生类引用和指针
	2. 基类中虚函数存在多个重载 则在派生类中应重新定义所有基类版本 如果少定义则隐藏哪个版本
*/

/*
保护: protected  
在基类相当于私有private  在派生类相当于基类的public
*/



/*
抽象基类: 
	两个对象有很多共同点 但是他们的行为却有很大的不同 因此可以定义一个 ABC抽象基类来描述他们所具有得到共同特点
	注意:  定义ABC抽象基类必须在类声明中含有虚函数的声明后面加上 =0 来使其成为 纯虚函数  这样他才是一个真正的抽象基类
*/




/*
抽象基类实例
*/

const int CLIENTS = 4;
int main()
{
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
			p_clients[i] = new Brass(temp,tempnum,tempbal);
		}
		else
		{
			double tempmax, temprate;
			cout << "请输入最大借款金额: ";
			cin >> tempmax;
			cout << "请输入借款利率: ";
			cin >> temprate;
			//创建派生类
			p_clients[i] = new BrassPlus{ temp,tempnum,tempbal,tempmax,temprate };
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

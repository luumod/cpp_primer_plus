
#ifndef WORK_H_
#define WORK_H_
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//抽象基类
#if 0
class Worker
{
private:
	std::string fullname;
	long id;
public:
	Worker()
		:fullname("no one"),id(0L){}
	Worker(const std::string& s, long n)
		:fullname(s), id(n){}
	virtual ~Worker() = 0;	//纯虚函数
	virtual void Set();
	virtual void Show()const;
};

//派生类 1
class Waiter:public Worker
{
private:
	int panache;

public:
	Waiter()
		:Worker(), panache(0) {}
	Waiter(const std::string& s, long n, int p = 0)
		:Worker(s, n), panache(p) {}
	Waiter(const Worker& wk, int p = 0)
		:Worker(wk), panache(p) {}
	void Set();
	void Show()const;
};

//派生类 2
class Singer :public Worker
{
protected:
	enum
	{	//声音类型
		other,
		alot,
		contralto,
		soprano,
		bass,
		baritone,
		tenor
	};
	enum
	{
		Vtypes=7
	};
private:
	//static char* pv[Vtypes];
	const char* pv[Vtypes] = { "other","alot","contralto","soprano",
		"bass","baritone","tenor" };
	int voice;
public:
	Singer()
		:Worker(), voice(other) {}
	Singer(const std::string& s, long n, int v = other)
		:Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other)
		:Worker(wk), voice(v) {}
	void Set();
	void Show()const;
};
#endif 


/* 
改进后的多重继承

为何要改进?  因此多个派生类继承同一个基类可能会出现二义性问题
	使用虚基类
*/



#if 1
class Worker
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Worker()
		:fullname("no one"), id(0L) {}

	Worker(const std::string& s, long n)
		:fullname(s), id(n) {}
	/*
	//纯虚函数
	*/
	virtual ~Worker() = 0;	
	virtual void Set() = 0;
	virtual void Show()const = 0;
};

/*
只要含有虚基类都要再构造函数中调用虚基类的构造函数。
*/

//派生类 1
class Waiter :virtual public Worker
{
private:
	int panache;
protected:
	void Data()const;
	void Get();
public:
	Waiter()
		:Worker(), panache(0) {}

	Waiter(const std::string& s, long n, int p = 0)
		:Worker(s, n), panache(p) {}

	Waiter(const Worker& wk, int p = 0)
		:Worker(wk), panache(p) {}
	void Set();
	void Show()const;
};

//派生类 2
class Singer :virtual public Worker
{
protected:
	enum
	{	//声音类型
		other,
		alot,
		contralto,
		soprano,
		bass,
		baritone,
		tenor
	};
	enum
	{
		Vtypes = 7
	};
	void Data()const;
	void Get();
private:
	const char* pv[Vtypes] = { "other","alot","contralto","soprano",
		"bass","baritone","tenor" };
	int voice;
public:
	Singer()
		:Worker(), voice(other) {}

	Singer(const std::string& s, long n, int v = other)
		:Worker(s, n), voice(v) {}

	Singer(const Worker& wk, int v = other)
		:Worker(wk), voice(v) {}
	void Set();
	void Show()const;
};

//派生类 3
class SingerWaiter:public Singer,public Waiter
{
protected:
	void Data()const;
	void Get();
public:
	SingerWaiter() {}
	SingerWaiter(const std::string& s, long n, int p = 0, int v = other)
		:Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}

	SingerWaiter(const Worker& wk, int p = 0, int v = other)
		:Worker(wk), Waiter(wk, p), Singer(wk, v) {}

	SingerWaiter(const Waiter& wk,int v = other)
		:Worker(wk), Waiter(wk), Singer(wk, v) {}

	SingerWaiter(const Singer& wk, int p = 0)
		:Worker(wk), Waiter(wk, p), Singer(wk) {}
	void Set();
	void Show()const;
};

#endif


/*
不适使用虚基类造成的二义性问题示例
*/
#if 0
class A
{
protected:
	int a = 5;
public:
	A()
	{
		cout << "a= " << a << endl;
	}
};

class A1 : public A
{
public:
	A1()
	{
		a += 10;
		cout << "a= " << a << endl;
	}
};

class A2 : public A
{
public:
	A2()
	{
		a += 20;
		cout << "a= " << a << endl;
	}
};

class A__last : public A1, public A2
{
public:
	A__last()
	{
		cout << "a= " << a << endl;
	}
};
/*
结果:	
	5 
	15
	5		//重复调用基类的构造函数  导致重复的a初始化
	25
	15
	25
*/
/*
虚基类使得:
	1. 对同一个虚基类的构造函数只调用一次
	2. 且是在第一次出现时调用;
*/
#endif

#endif // !WORK_H_

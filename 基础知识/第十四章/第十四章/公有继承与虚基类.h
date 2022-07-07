
#ifndef WORK_H_
#define WORK_H_
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//�������
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
	virtual ~Worker() = 0;	//���麯��
	virtual void Set();
	virtual void Show()const;
};

//������ 1
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

//������ 2
class Singer :public Worker
{
protected:
	enum
	{	//��������
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
�Ľ���Ķ��ؼ̳�

Ϊ��Ҫ�Ľ�?  ��˶��������̳�ͬһ��������ܻ���ֶ���������
	ʹ�������
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
	//���麯��
	*/
	virtual ~Worker() = 0;	
	virtual void Set() = 0;
	virtual void Show()const = 0;
};

/*
ֻҪ��������඼Ҫ�ٹ��캯���е��������Ĺ��캯����
*/

//������ 1
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

//������ 2
class Singer :virtual public Worker
{
protected:
	enum
	{	//��������
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

//������ 3
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
����ʹ���������ɵĶ���������ʾ��
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
���:	
	5 
	15
	5		//�ظ����û���Ĺ��캯��  �����ظ���a��ʼ��
	25
	15
	25
*/
/*
�����ʹ��:
	1. ��ͬһ�������Ĺ��캯��ֻ����һ��
	2. �����ڵ�һ�γ���ʱ����;
*/
#endif

#endif // !WORK_H_

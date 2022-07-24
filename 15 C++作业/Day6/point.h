

#ifndef ZHINENG_H_
#define ZHINENG_H_
#include <iostream>

class clever_ptr
{
private:
	int* n;
public:
	//构造函数
	clever_ptr(int* i) :n(i) {}
	//析构函数  自动删除
	~clever_ptr()
	{
		delete n;
	}

	int operator*();
	int operator[](int i);

	
	/*
	重载流运算符
	*/
	friend std::ostream& operator<<(std::ostream& os,clever_ptr& n);
};

#endif // !ZHINENG_H_

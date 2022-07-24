


#ifndef 自定义_H_
#define 自定义_H_
#include <iostream>

/*
封装一个自用的数据类型
*/
class 于良浩
{
private:
	int num;
public:
	//构造函数
	于良浩(int n = 1) :num(n) {}
	//析构函数
	~于良浩() {}
	//复制构造函数
	于良浩(const 于良浩& n);
	void print()const;
	/*
	重载算术运算符
	*/
	于良浩 operator+(const 于良浩& n);
	于良浩 operator-(const 于良浩& n);
	于良浩 operator*(const 于良浩& n);
	于良浩 operator/(const 于良浩& n);
	于良浩 operator=(const 于良浩& n);

	于良浩 operator+=(const 于良浩& n);
	于良浩 operator-=(const 于良浩& n);
	于良浩 operator*=(const 于良浩& n);
	于良浩 operator/=(const 于良浩& n);

	friend 于良浩 operator+(int i, const 于良浩& n);
	friend 于良浩 operator-(int i, const 于良浩& n);
	friend 于良浩 operator*(int i, const 于良浩& n);
	friend 于良浩 operator/(int i, const 于良浩& n);

	/*
	外部访问接口 
	*/
	int GetNum()const
	{
		return num;
	}
	int& GetNum()
	{
		return num;
	}

};


#endif



#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <string>
using std::string;

class String
{
private:
	char* pstr;
	int Cursize;
public:
	//构造函数
	String();
	String(const char* s);
	//析构函数
	~String()
	{
		delete[] pstr;
	}
	//复制构造函数
	String(const String& s);

	//重载基本运算符
	String& operator=(const String& s1);
	bool operator>(const String& s1);
	bool operator<(const String& s1);
	bool operator==(const String& s1);
	char operator[](int i);
	String operator+(const String& s);

	//友元函数  
	//friend String operator+(const String& s1, const String& s2);	//不用友元
	friend std::istream& operator>>(std::istream& is,String& s1);
	friend std::ostream& operator<<(std::ostream& os,const String& s1);

	//类方法
	int size()const
	{
		return this->Cursize;
	}
	bool empty()const
	{
		return Cursize == 0;
	}
	const char* c_str()const
	{
		return pstr;
	}
	const char* data()const
	{
		return pstr;
	}
};

#endif
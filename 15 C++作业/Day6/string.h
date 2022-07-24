

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
	//���캯��
	String();
	String(const char* s);
	//��������
	~String()
	{
		delete[] pstr;
	}
	//���ƹ��캯��
	String(const String& s);

	//���ػ��������
	String& operator=(const String& s1);
	bool operator>(const String& s1);
	bool operator<(const String& s1);
	bool operator==(const String& s1);
	char operator[](int i);
	String operator+(const String& s);

	//��Ԫ����  
	//friend String operator+(const String& s1, const String& s2);	//������Ԫ
	friend std::istream& operator>>(std::istream& is,String& s1);
	friend std::ostream& operator<<(std::ostream& os,const String& s1);

	//�෽��
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
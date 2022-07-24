#include "string.h"

String::String()
{
	pstr = nullptr;
	Cursize = 0;
}

String::String(const char* s)
{
	Cursize = strlen(s);
	pstr = new char[Cursize + 1];
	strcpy(this->pstr, s);
}

String::String(const String& s)
{
	this->Cursize = s.Cursize;
	pstr = new char[Cursize + 1];
	strcpy(this->pstr, s.pstr);
}

String& String::operator=(const String& s1)
{
	// TODO: 在此处插入 return 语句
	this->Cursize = s1.Cursize;
	if (pstr != nullptr)
	{
		delete pstr;
	}
	pstr = new char[Cursize + 1];
	strcpy(pstr, s1.pstr);
	return *this;
}

bool String::operator>(const String& s1)
{

	return strcmp(this->pstr, s1.pstr) > 0;
}

bool String::operator<(const String& s1)
{
	return strcmp(this->pstr, s1.pstr) < 0;
}

bool String::operator==(const String& s1)
{
	return strcmp(this->pstr, s1.pstr) == 0;
}

char String::operator[](int i)
{
	return this->pstr[i];
}

/*
不用友元的形式
*/
String String::operator+(const String& s)
{
	String temp;
	temp.Cursize = s.Cursize + this->Cursize;
	temp.pstr = new char[temp.Cursize + 1];
	strcpy(temp.pstr, this->pstr);
	strcat(temp.pstr, s.pstr);
	return temp;
}

//String operator+(const String& s1, const String& s2)
//{
//	String s;
//	s.Cursize = s1.Cursize + s2.Cursize;
//	s.pstr = new char[s.Cursize + 1];
//	strcpy(s.pstr, s1.pstr);
//	strcat(s.pstr, s2.pstr);
//	return s;
//}

std::istream& operator>>(std::istream& is, String& s1)
{
	char temp[1024];
	is >> temp;
	s1.Cursize = strlen(temp);
	s1.pstr = new char[s1.Cursize + 1];
	strcpy(s1.pstr, temp);
	return is;
}

std::ostream& operator<<(std::ostream& os, const String& s1)
{
	if (s1.pstr == nullptr)
	{
		os << "nullptr! ";
		return os;
	}
	os << s1.pstr;
	return os;
}

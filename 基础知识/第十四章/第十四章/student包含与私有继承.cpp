#include "student包含与私有继承.h"
#include <string>
using std::ostream;
using std::endl;
using std::istream;
using std::string;

/*
包含对象成员的类
*/
//包含使用对象名来调用方法
#if 0
std::ostream& Student::arr_out(std::ostream& os) const
{
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
			if (i % 5 == 4)
			{
				os << endl;
			}
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
	{
		os << "empty array! ";
	}
	return os;
}


double Student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0.0;
}

const std::string& Student::Name() const
{
	return name;// TODO: 在此处插入 return 语句
}

double& Student::operator[](int i)
{
	return scores[i]; // TODO: 在此处插入 return 语句
}

double Student::operator[](int i) const
{
	return scores[i];
}

std::istream& operator>>(std::istream& is, Student& stu)
{
	is >> stu.name;
	// TODO: 在此处插入 return 语句
	return is;
}

std::istream& getline(std::istream& is, Student& stu)
{
	getline(is, stu.name);
	// TODO: 在此处插入 return 语句
	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& stu)
{
	// stu.name 是string成员 因此程序会调用 operator<<(std::ostream& os, const string& )
	os << "Scores for " << stu.name << ": \n";
	// 但是valarray 没有<< 的实现 因此需要自己实现 
	stu.arr_out(os);	//辅助函数
	return os;
}
#endif


//私有继承时使用类名和作用域解析符来调用方法
std::ostream& Student::arr_out(std::ostream& os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
			{
				os << endl;
			}
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
	{
		os << "empty array! ";
	}
	return os;
}


double Student::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0.0;
}

const std::string& Student::Name() const
{
	//访问基类对象
	//调用Student对象中继承而来的string对象
	return (const string&)*this;
}

double& Student::operator[](int i)
{
	return ArrayDb::operator[](i); 
}

double Student::operator[](int i) const
{
	return  ArrayDb::operator[](i);
}

std::istream& operator>>(std::istream& is, Student& stu)
{
	//
	is >> (string&)stu;
	return is;
}

std::istream& getline(std::istream& is, Student& stu)
{
	getline(is, (string&)stu);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& stu)
{
	//访问基类的友元函数
	os << "Scores for " << (const string&) stu  << ": \n";
	// 但是valarray 没有<< 的实现 因此需要自己实现 
	stu.arr_out(os);	//辅助函数
	return os;
}
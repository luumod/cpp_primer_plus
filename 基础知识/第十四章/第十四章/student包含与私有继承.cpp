#include "student������˽�м̳�.h"
#include <string>
using std::ostream;
using std::endl;
using std::istream;
using std::string;

/*
���������Ա����
*/
//����ʹ�ö����������÷���
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
	return name;// TODO: �ڴ˴����� return ���
}

double& Student::operator[](int i)
{
	return scores[i]; // TODO: �ڴ˴����� return ���
}

double Student::operator[](int i) const
{
	return scores[i];
}

std::istream& operator>>(std::istream& is, Student& stu)
{
	is >> stu.name;
	// TODO: �ڴ˴����� return ���
	return is;
}

std::istream& getline(std::istream& is, Student& stu)
{
	getline(is, stu.name);
	// TODO: �ڴ˴����� return ���
	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& stu)
{
	// stu.name ��string��Ա ��˳������� operator<<(std::ostream& os, const string& )
	os << "Scores for " << stu.name << ": \n";
	// ����valarray û��<< ��ʵ�� �����Ҫ�Լ�ʵ�� 
	stu.arr_out(os);	//��������
	return os;
}
#endif


//˽�м̳�ʱʹ������������������������÷���
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
	//���ʻ������
	//����Student�����м̳ж�����string����
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
	//���ʻ������Ԫ����
	os << "Scores for " << (const string&) stu  << ": \n";
	// ����valarray û��<< ��ʵ�� �����Ҫ�Լ�ʵ�� 
	stu.arr_out(os);	//��������
	return os;
}
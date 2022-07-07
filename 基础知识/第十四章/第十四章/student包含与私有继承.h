


#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
#include <valarray>


/*
���������Ա����   �����汾
*/
#if 0
class Student
{
private:
	//˽�г�Ա����ʽ���������Ա
	typedef std::valarray<double> ArrayDb;	//������double���͵�����
	std::string name;
	ArrayDb scores;	
	//˽�з���
	std::ostream& arr_out(std::ostream& os)const;
public:
	/*
	���캯����ʼ������ ��Ա�Ķ��� ����ڳ�ʼ���б���ʹ�ó�Ա��������������
	��ʼ���б���õ�˳��Ϊ �����ĳ�Ա˳��
	*/
	Student() 
		:name("Null Student"), scores() {}	//��ʼ���б��е�ÿһ���ٵ����ض��Ĺ��캯��
	explicit Student(const std::string& s)
		:name(s),scores(){}
	/*
	explicit ��ֹ���������캯������ʽת��
	*/
	explicit Student(int n) :name("Nully"), scores(n) {}
	Student(const std::string& s,int n)
		:name(s), scores(n) {}
	Student(const std::string& s, const ArrayDb& a)
		:name(s), scores(a) {}
	Student(const char* str,const double * pb,int n)
		:name(str),scores(pb,n){}

	~Student() {}
	double Average()const;
	const std::string& Name()const;
	double& operator[](int i);		//���Ա��޸ĵ��±�����
	double operator[](int i)const;	//�޷����޸ĵ��±���ʾ
	//��Ԫ����
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};
#endif

/*
���������Ա����   ˽�м̳а汾
	˽�м̳� privateĬ��
		����Ĺ��з�������Ϊ�������˽�з���
*/

//���ؼ̳�   ˽�м̳�
class Student :private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;	//������double���͵�����
	//std::string name;
	//ArrayDb scores;	ʡ����ʽ��������  ���ڹ�����ʹ������
	//˽�з���
	std::ostream& arr_out(std::ostream& os)const;
public:
	Student()
		:std::string("Null Student"), ArrayDb() {}	//��ʼ���б��е�ÿһ���ٵ����ض��Ĺ��캯��
	explicit Student(const std::string& s)
		:std::string(s), ArrayDb() {}
	/*
	explicit ��ֹ���������캯������ʽת��
	*/
	explicit Student(int n) :std::string("Nully"), ArrayDb(n) {}
	Student(const std::string& s, int n)
		:std::string(s), ArrayDb(n) {}
	Student(const std::string& s, const ArrayDb& a)
		:std::string(s), ArrayDb(a) {}
	Student(const char* str, const double* pb, int n)
		:std::string(str), ArrayDb(pb, n) {}

	~Student() {}
	using std::valarray<double>::min;	//using���� 
	double Average()const;
	const std::string& Name()const;
	double& operator[](int i);
	double operator[](int i)const;
	//��Ԫ����
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);

};

#endif
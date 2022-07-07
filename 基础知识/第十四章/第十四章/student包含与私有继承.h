


#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
#include <valarray>


/*
包含对象成员的类   包含版本
*/
#if 0
class Student
{
private:
	//私有成员中显式命名对象成员
	typedef std::valarray<double> ArrayDb;	//类似于double类型的数组
	std::string name;
	ArrayDb scores;	
	//私有方法
	std::ostream& arr_out(std::ostream& os)const;
public:
	/*
	构造函数初始化的是 成员的对象 因此在初始化列表中使用成员名，而不是类名
	初始化列表调用的顺序为 声明的成员顺序
	*/
	Student() 
		:name("Null Student"), scores() {}	//初始化列表中的每一项再调用特定的构造函数
	explicit Student(const std::string& s)
		:name(s),scores(){}
	/*
	explicit 防止单参数构造函数的隐式转换
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
	double& operator[](int i);		//可以被修改的下标引用
	double operator[](int i)const;	//无法被修改的下标显示
	//友元函数
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};
#endif

/*
包含对象成员的类   私有继承版本
	私有继承 private默认
		基类的公有方法将成为派生类的私有方法
*/

//多重继承   私有继承
class Student :private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;	//类似于double类型的数组
	//std::string name;
	//ArrayDb scores;	省略显式对象名称  并在构造中使用类名
	//私有方法
	std::ostream& arr_out(std::ostream& os)const;
public:
	Student()
		:std::string("Null Student"), ArrayDb() {}	//初始化列表中的每一项再调用特定的构造函数
	explicit Student(const std::string& s)
		:std::string(s), ArrayDb() {}
	/*
	explicit 防止单参数构造函数的隐式转换
	*/
	explicit Student(int n) :std::string("Nully"), ArrayDb(n) {}
	Student(const std::string& s, int n)
		:std::string(s), ArrayDb(n) {}
	Student(const std::string& s, const ArrayDb& a)
		:std::string(s), ArrayDb(a) {}
	Student(const char* str, const double* pb, int n)
		:std::string(str), ArrayDb(pb, n) {}

	~Student() {}
	using std::valarray<double>::min;	//using声明 
	double Average()const;
	const std::string& Name()const;
	double& operator[](int i);
	double operator[](int i)const;
	//友元函数
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);

};

#endif
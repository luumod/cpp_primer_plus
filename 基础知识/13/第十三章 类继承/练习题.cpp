#include <iostream>
#include <cstring>
#include "练习题.h"



//第一题
////构造函数
//Cd::Cd(const char* s1, const char* s2, int n, double x)
//{
//	strcpy(performate, s1);
//	strcpy(label, s2);
//	selections = n;
//	playtime = x;
//}
//
////复制构造函数
//Cd::Cd(const Cd& d)
//{
//	strcpy(performate, d.performate);
//	strcpy(label, d.label);
//	selections = d.selections;
//	playtime = d.playtime;
//}
//
//Cd::Cd()
//{
//}
//
////析构函数
//Cd::~Cd()
//{
//}
//
//
//void Cd::Report() const
//{
//	std::cout << "performate: " << performate << std::endl;
//	std::cout << "label: " << label << std::endl;
//	std::cout << "selections: " << selections << std::endl;
//	std::cout << "playtime: " << playtime << std::endl;
//}
//
//Cd& Cd::operator=(const Cd& d)
//{
//	if (this == &d)
//		return *this;
//	strcpy(performate, d.performate);
//	strcpy(label, d.label);
//	selections = d.selections;
//	playtime = d.playtime;
//	return *this;
//	// TODO: 在此处插入 return 语句
//}
//
//
////派生类
//Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
//	:Cd(s1,s2,n,x)	//调用基类的构造函数
//{
//	strcpy(name, s3);
//}
//
////复制构造函数
//Classic::Classic(const Classic& d)
//	:Cd(d)	//调用基类的构造函数
//{
//	strcpy(name, d.name);
//}
//
//Classic::Classic()
//{
//}
//
//
//Classic::~Classic()
//{
//}
//
//void Classic::Report() const
//{
//	Cd::Report();		//调用基类方法
//	std::cout << "name: " << name << std::endl;
//}
//
//Classic& Classic::operator=(const Classic& d)
//{
//	if (this == &d)
//		return *this;
//	//先赋值基类中的数据
//	Cd::operator=(d);	//*this=d
//
//	strcpy(name, d.name);
//	// TODO: 在此处插入 return 语句
//	return *this;
//}


//using std::strlen;
//Cd::Cd(const char* s1, const char* s2, int n, double x)
//{
//	performate = new char[strlen(s1)+1];
//	strcpy(performate, s1);
//	label = new char[strlen(s2) + 1];
//	strcpy(label, s2);
//	selections = n;
//	playtime = x;
//}
//
////复制构造函数
//Cd::Cd(const Cd& d)
//{
//	performate = new char[strlen(d.performate) + 1];
//	strcpy(performate, d.performate);
//	label = new char[strlen(d.label) + 1];
//	strcpy(label, d.label);
//	selections = d.selections;
//	playtime = d.playtime;
//}
//
////析构函数
//Cd::~Cd()
//{
//	delete[]performate;
//	delete[]label;
//}
//
//void Cd::Report() const
//{
//	std::cout << "performate: " << performate << std::endl;
//	std::cout << "label: " << label << std::endl;
//	std::cout << "selections: " << selections << std::endl;
//	std::cout << "playtime: " << playtime << std::endl;
//}
//
//Cd& Cd::operator=(const Cd& d)
//{
//	if (this == &d)
//		return *this;
//	delete[]performate;
//	delete[]label;
//	performate = new char[strlen(d.performate) + 1];
//	strcpy(performate, d.performate);
//	label = new char[strlen(d.label) + 1];
//	strcpy(label, d.label);
//	selections = d.selections;
//	playtime = d.playtime;
//	return *this;
//	// TODO: 在此处插入 return 语句
//}
//
//
////派生类  使用new
//Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
//	:Cd(s1,s2,n,x)	//成员初始化列表
//{
//	name = new char[strlen(s3) + 1];
//	strcpy(name, s3);
//}
//
////复制构造函数
//Classic::Classic(const Classic& d)
//	:Cd(d)	//调用基类的构造函数
//{
//	name = new char[strlen(d.name) + 1];
//	strcpy(name, d.name);
//}
//
//
//Classic::~Classic()
//{
//	delete[]name;
//}
//
//void Classic::Report() const
//{
//	Cd::Report();		//调用基类方法
//	std::cout << "name: " << name << std::endl;
//}
//
//Classic& Classic::operator=(const Classic& d)
//{
//	if (this == &d)
//		return *this;
//	//先赋值基类中的数据
//	Cd::operator=(d);	//*this=d
//
//	name = new char[strlen(d.name) + 1];
//	strcpy(name, d.name);
//	// TODO: 在此处插入 return 语句
//	return *this;
//}





/*
第三题
*/

ABC::ABC(const char* s, int rat)
{
	label = new char[strlen(s) + 1];
	strcpy(label, s);
	rating = rat;
}

ABC::ABC(const ABC& t)
{
	label = new char[strlen(t.label) + 1];
	strcpy(label, t.label);
	rating = t.rating;
}

ABC& ABC::operator=(const ABC& r)
{
	if (this == &r)
		return *this;
	delete[]label;
	label = new char[strlen(r.label) + 1];
	strcpy(label, r.label);
	rating = r.rating;
	// TODO: 在此处插入 return 语句
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ABC& rs)
{
	os << "label: " << rs.label << std::endl;
	os << "rating: " << rs.rating << std::endl;
	return os;
}

//派生类 0
baseDMA::baseDMA(const char* s, int r)
	:ABC(s,r)
{
}

baseDMA::baseDMA(const baseDMA& rs)
	:ABC(rs)
{
}

//显示数据
void baseDMA::View() const
{
	std::cout << "label: " << label << std::endl;
	std::cout << "rating: " << rating << std::endl;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	// TODO: 在此处插入 return 语句
	return os;
}

/*
派生类 1: 不使用new
*/
lackDMA::lackDMA(const char* s, const char* l, int r)
	:ABC(l, r)
{
	std::strncpy(color, s, 39);
	color[39] = '\0';
}

lackDMA::lackDMA(const char* c, const baseDMA& hs)
	:ABC(hs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lackDMA& rs)
{
	/*
	强转换为基类型 使得派生类可以访问基类成员
	*/
	os << (const ABC&)rs;
	os << "Color: " << rs.color << std::endl;
	return os;
}
void lackDMA::View() const
{
	std::cout << "label: " << label << std::endl;
	std::cout << "rating: " << rating << std::endl;
	std::cout << "color: " << color << std::endl;
}



/*
派生类 2: 使用new
*/
hasDMA::hasDMA(const char* s, const char* l, int r)
	:ABC(l, r)	//成员初始化列表
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& hs)
	:ABC(hs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

//复制构造函数： 基类的引用可以指向派生类型
hasDMA::hasDMA(const hasDMA& rs)
	:ABC(rs)
	/*
		注意到此时使用成员初始化列表将rs传入基类中，但是rs为派生类
	基类的复制构造函数中没有与派生类符合的函数形参,但是基类的引用
	也可以指向派生类型
		因此baseDMA复制构造函数将使用hasDMA参数的baseDMA部分来构造新对象的baseDMA部分
	*/
{
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
}

hasDMA::~hasDMA()
{
	delete[]style;
}

//赋值运算符: 
hasDMA& hasDMA::operator=(const hasDMA& rs)
{
	if (this == &rs)
	{
		return *this;
	}
	/*
	先赋值基类中的成员数据
	*/
	ABC::operator=(rs);		//*this=rs
	/*
	再赋值派生类中新增的成员数据
	*/
	delete[]style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	// TODO: 在此处插入 return 语句
	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& rs)
{
	/*
	将派生类强制转换为 baseDMA的基类 使得派生类可以访问基类的成员
	*/
	os << (const ABC&)rs;
	os << "Style: " << rs.style << std::endl;
	return os;
}
void hasDMA::View() const
{
	std::cout << "label: " << label << std::endl;
	std::cout << "rating: " << rating << std::endl;
	std::cout << "style: " << style << std::endl;
}







/*
第四题
*/

Port::Port(const char* br, const char* s, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	int len = strlen(s);
	strcpy(style, s);
	style[len] = '\0';
	bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	int len = strlen(p.style);
	strcpy(style, p.style);
	style[len] = '\0';
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;
	delete[]brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	int len = strlen(p.style);
	strcpy(style, p.style);
	style[len] = '\0';
	bottles = p.bottles;
	// TODO: 在此处插入 return 语句
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	// TODO: 在此处插入 return 语句
	return *this;
}

Port& Port::operator-=(int b)
{
	if (bottles >= b)
	{
		bottles -= b;
	}
	else
	{
		std::cout << "bottles为负!" << std::endl;
	}
	// TODO: 在此处插入 return 语句
	return *this;
}

void Port::show() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles << std::endl;
	// TODO: 在此处插入 return 语句
	return os;
}


//派生类
//默认构造函数
VintagePort::VintagePort()
{
	Port::Port("none", "none", 0);	//初始化基类
	nickname = new char[strlen("none") + 1];
	strcpy(nickname, "none");
	year = 0;
}

VintagePort::VintagePort(const char* br, const char* st,int b, const char* nn, int y)
	:Port(br,st,b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp)
	:Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return *this;
	Port::operator=(vp);	//*this=vp  赋值基类部分
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	// TODO: 在此处插入 return 语句
	return *this;
}

void VintagePort::show() const
{
	Port::show();
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	os << (const Port&)vp;	//强制类型转换调用Port基类的重载输出流运算符方法;
	os << vp.nickname << ", " << vp.year << std::endl;
	// TODO: 在此处插入 return 语句
	return os;
}
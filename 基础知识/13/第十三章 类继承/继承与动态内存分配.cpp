//
//#include "继承与动态内存分配.h"
//#include <cstring>
//
//baseDMA::baseDMA(const char* s, int r)
//{
//	label = new char[std::strlen(s) + 1];
//	std::strcpy(label, s);
//	rating = r;
//}
//
//baseDMA::baseDMA(const baseDMA& rs)
//{
//	label = new char[std::strlen(rs.label) + 1];
//	std::strcpy(label, rs.label);
//	rating = rs.rating;
//}
//
//baseDMA::~baseDMA()
//{
//	delete[]label;
//}
//
//baseDMA& baseDMA::operator=(const baseDMA& rs)
//{
//	if (this == &rs)
//	{
//		return *this;
//	}
//	delete[]label;
//	label = new char[std::strlen(rs.label) + 1];
//	std::strcpy(label, rs.label);
//	rating = rs.rating;
//	// TODO: 在此处插入 return 语句
//	return *this;
//}
//
////显示数据
//void baseDMA::View() const
//{
//	std::cout << "label: " << label << std::endl;
//	std::cout << "rating: " << rating << std::endl;
//}
//
//std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
//{
//	os << "Label: " << rs.label << std::endl;
//	os << "Rating: " << rs.rating << std::endl;
//	// TODO: 在此处插入 return 语句
//	return os;
//}
//
///*
//派生类 1: 不使用new
//*/
//lackDMA::lackDMA(const char* s, const char* l, int r)
//	:baseDMA(l, r)
//{
//	std::strncpy(color, s, 39);
//	color[39] = '\0';
//}
//
//lackDMA::lackDMA(const char* c, const baseDMA& hs)
//	:baseDMA(hs)
//{
//	std::strncpy(color, c, COL_LEN - 1);
//	color[COL_LEN - 1] = '\0';
//}
//
//std::ostream& operator<<(std::ostream& os, const lackDMA& rs)
//{
//	/*
//	强转换为基类型 使得派生类可以访问基类成员
//	*/
//	os << (const baseDMA&)rs;	
//	os << "Color: " << rs.color << std::endl;
//	return os;
//}
//
//
///*
//派生类 2: 使用new
//*/
//hasDMA::hasDMA(const char* s, const char* l, int r)
//	:baseDMA(l, r)	//成员初始化列表
//{
//	style = new char[std::strlen(s) + 1];
//	std::strcpy(style, s);
//}
//
//hasDMA::hasDMA(const char* s, const baseDMA& hs)
//	:baseDMA(hs)
//{
//	style = new char[std::strlen(s) + 1];
//	std::strcpy(style, s);
//}
//
////复制构造函数： 基类的引用可以指向派生类型
//hasDMA::hasDMA(const hasDMA& rs)
//	:baseDMA(rs)
//	/*
//		注意到此时使用成员初始化列表将rs传入基类中，但是rs为派生类 
//	基类的复制构造函数中没有与派生类符合的函数形参,但是基类的引用
//	也可以指向派生类型 
//		因此baseDMA复制构造函数将使用hasDMA参数的baseDMA部分来构造新对象的baseDMA部分
//	*/
//{
//	style = new char[std::strlen(rs.style) + 1];
//	std::strcpy(style, rs.style);
//}
//
//hasDMA::~hasDMA()
//{
//	delete[]style;
//}
//
////赋值运算符: 
//hasDMA& hasDMA::operator=(const hasDMA& rs)
//{
//	if (this == &rs)
//	{
//		return *this;
//	}
//	/*
//	先赋值基类中的成员数据
//	*/
//	baseDMA::operator=(rs);		//*this=rs
//	/*
//	再赋值派生类中新增的成员数据
//	*/
//	delete[]style;
//	style = new char[std::strlen(rs.style) + 1];
//	std::strcpy(style, rs.style);
//	// TODO: 在此处插入 return 语句
//	return *this;
//}
//
//std::ostream& operator<<(std::ostream& os, const hasDMA& rs)
//{
//	/*
//	将派生类强制转换为 baseDMA的基类 使得派生类可以访问基类的成员
//	*/
//	os << (const baseDMA&)rs;
//	os << "Style: " << rs.style << std::endl;
//	return os;
//}
//
//

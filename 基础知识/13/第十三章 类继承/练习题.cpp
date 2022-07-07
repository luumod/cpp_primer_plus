#include <iostream>
#include <cstring>
#include "��ϰ��.h"



//��һ��
////���캯��
//Cd::Cd(const char* s1, const char* s2, int n, double x)
//{
//	strcpy(performate, s1);
//	strcpy(label, s2);
//	selections = n;
//	playtime = x;
//}
//
////���ƹ��캯��
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
////��������
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
//	// TODO: �ڴ˴����� return ���
//}
//
//
////������
//Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
//	:Cd(s1,s2,n,x)	//���û���Ĺ��캯��
//{
//	strcpy(name, s3);
//}
//
////���ƹ��캯��
//Classic::Classic(const Classic& d)
//	:Cd(d)	//���û���Ĺ��캯��
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
//	Cd::Report();		//���û��෽��
//	std::cout << "name: " << name << std::endl;
//}
//
//Classic& Classic::operator=(const Classic& d)
//{
//	if (this == &d)
//		return *this;
//	//�ȸ�ֵ�����е�����
//	Cd::operator=(d);	//*this=d
//
//	strcpy(name, d.name);
//	// TODO: �ڴ˴����� return ���
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
////���ƹ��캯��
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
////��������
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
//	// TODO: �ڴ˴����� return ���
//}
//
//
////������  ʹ��new
//Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
//	:Cd(s1,s2,n,x)	//��Ա��ʼ���б�
//{
//	name = new char[strlen(s3) + 1];
//	strcpy(name, s3);
//}
//
////���ƹ��캯��
//Classic::Classic(const Classic& d)
//	:Cd(d)	//���û���Ĺ��캯��
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
//	Cd::Report();		//���û��෽��
//	std::cout << "name: " << name << std::endl;
//}
//
//Classic& Classic::operator=(const Classic& d)
//{
//	if (this == &d)
//		return *this;
//	//�ȸ�ֵ�����е�����
//	Cd::operator=(d);	//*this=d
//
//	name = new char[strlen(d.name) + 1];
//	strcpy(name, d.name);
//	// TODO: �ڴ˴����� return ���
//	return *this;
//}





/*
������
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
	// TODO: �ڴ˴����� return ���
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ABC& rs)
{
	os << "label: " << rs.label << std::endl;
	os << "rating: " << rs.rating << std::endl;
	return os;
}

//������ 0
baseDMA::baseDMA(const char* s, int r)
	:ABC(s,r)
{
}

baseDMA::baseDMA(const baseDMA& rs)
	:ABC(rs)
{
}

//��ʾ����
void baseDMA::View() const
{
	std::cout << "label: " << label << std::endl;
	std::cout << "rating: " << rating << std::endl;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	// TODO: �ڴ˴����� return ���
	return os;
}

/*
������ 1: ��ʹ��new
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
	ǿת��Ϊ������ ʹ����������Է��ʻ����Ա
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
������ 2: ʹ��new
*/
hasDMA::hasDMA(const char* s, const char* l, int r)
	:ABC(l, r)	//��Ա��ʼ���б�
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

//���ƹ��캯���� ��������ÿ���ָ����������
hasDMA::hasDMA(const hasDMA& rs)
	:ABC(rs)
	/*
		ע�⵽��ʱʹ�ó�Ա��ʼ���б�rs��������У�����rsΪ������
	����ĸ��ƹ��캯����û������������ϵĺ����β�,���ǻ��������
	Ҳ����ָ����������
		���baseDMA���ƹ��캯����ʹ��hasDMA������baseDMA�����������¶����baseDMA����
	*/
{
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
}

hasDMA::~hasDMA()
{
	delete[]style;
}

//��ֵ�����: 
hasDMA& hasDMA::operator=(const hasDMA& rs)
{
	if (this == &rs)
	{
		return *this;
	}
	/*
	�ȸ�ֵ�����еĳ�Ա����
	*/
	ABC::operator=(rs);		//*this=rs
	/*
	�ٸ�ֵ�������������ĳ�Ա����
	*/
	delete[]style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	// TODO: �ڴ˴����� return ���
	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& rs)
{
	/*
	��������ǿ��ת��Ϊ baseDMA�Ļ��� ʹ����������Է��ʻ���ĳ�Ա
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
������
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
	// TODO: �ڴ˴����� return ���
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	// TODO: �ڴ˴����� return ���
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
		std::cout << "bottlesΪ��!" << std::endl;
	}
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
	return os;
}


//������
//Ĭ�Ϲ��캯��
VintagePort::VintagePort()
{
	Port::Port("none", "none", 0);	//��ʼ������
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
	Port::operator=(vp);	//*this=vp  ��ֵ���ಿ��
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	// TODO: �ڴ˴����� return ���
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
	os << (const Port&)vp;	//ǿ������ת������Port�����������������������;
	os << vp.nickname << ", " << vp.year << std::endl;
	// TODO: �ڴ˴����� return ���
	return os;
}
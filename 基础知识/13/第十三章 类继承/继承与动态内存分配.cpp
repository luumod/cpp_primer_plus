//
//#include "�̳��붯̬�ڴ����.h"
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
//	// TODO: �ڴ˴����� return ���
//	return *this;
//}
//
////��ʾ����
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
//	// TODO: �ڴ˴����� return ���
//	return os;
//}
//
///*
//������ 1: ��ʹ��new
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
//	ǿת��Ϊ������ ʹ����������Է��ʻ����Ա
//	*/
//	os << (const baseDMA&)rs;	
//	os << "Color: " << rs.color << std::endl;
//	return os;
//}
//
//
///*
//������ 2: ʹ��new
//*/
//hasDMA::hasDMA(const char* s, const char* l, int r)
//	:baseDMA(l, r)	//��Ա��ʼ���б�
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
////���ƹ��캯���� ��������ÿ���ָ����������
//hasDMA::hasDMA(const hasDMA& rs)
//	:baseDMA(rs)
//	/*
//		ע�⵽��ʱʹ�ó�Ա��ʼ���б�rs��������У�����rsΪ������ 
//	����ĸ��ƹ��캯����û������������ϵĺ����β�,���ǻ��������
//	Ҳ����ָ���������� 
//		���baseDMA���ƹ��캯����ʹ��hasDMA������baseDMA�����������¶����baseDMA����
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
////��ֵ�����: 
//hasDMA& hasDMA::operator=(const hasDMA& rs)
//{
//	if (this == &rs)
//	{
//		return *this;
//	}
//	/*
//	�ȸ�ֵ�����еĳ�Ա����
//	*/
//	baseDMA::operator=(rs);		//*this=rs
//	/*
//	�ٸ�ֵ�������������ĳ�Ա����
//	*/
//	delete[]style;
//	style = new char[std::strlen(rs.style) + 1];
//	std::strcpy(style, rs.style);
//	// TODO: �ڴ˴����� return ���
//	return *this;
//}
//
//std::ostream& operator<<(std::ostream& os, const hasDMA& rs)
//{
//	/*
//	��������ǿ��ת��Ϊ baseDMA�Ļ��� ʹ����������Է��ʻ���ĳ�Ա
//	*/
//	os << (const baseDMA&)rs;
//	os << "Style: " << rs.style << std::endl;
//	return os;
//}
//
//

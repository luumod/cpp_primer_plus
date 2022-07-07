



#ifndef CD_H_
#define CD_H_

#include <iostream>
//��һ��
//class Cd
//{
//private:
//	char performate[50];
//	char label[20];
//	int selections;
//	double playtime;
//public:
//	Cd(const char* s1, const char* s2, int n, double x);
//	Cd(const Cd& d);
//	Cd();
//	~Cd();
//	virtual void Report()const;
//	Cd& operator=(const Cd& d);
//};
//
////������
//class Classic : public Cd
//{
//private:
//	char name[50];
//public:
//	Classic(const char* s1, const char* s2, const char* s3,int n, double x);
//	Classic(const Classic& d);
//	Classic();
//	~Classic();
//	virtual void Report()const;
//	Classic& operator=(const Classic& d);
//};

//�ڶ���  ʹ��new
//class Cd
//{
//private:
//	char* performate;
//	char* label;
//	int selections;
//	double playtime;
//public:
//	Cd(const char* s1="none", const char* s2="none", int n=0, double x=0);
//	Cd(const Cd& d);
//	~Cd();
//	virtual void Report()const;
//	Cd& operator=(const Cd& d);
//};
//
////������
//class Classic : public Cd
//{
//private:
//	char* name;
//public:
//	Classic(const char* s1 = "none", const char* s2 = "none", const char* s3 = "none", int n = 0, double x = 0);
//	Classic(const Classic& d);
//	~Classic();
//	virtual void Report()const;
//	Classic& operator=(const Classic& d);
//};


//������
class ABC
{
protected:
	char* label;
	int rating;
public:
	//Ĭ�Ϲ��캯��
	ABC(const char* s = "none", int rat = 0);
	//���ƹ��캯��
	ABC(const ABC& t);
	//������������
	virtual~ABC() { delete[]label; }
	//���ظ�ֵ�����
	ABC& operator=(const ABC& r);
	virtual void View()const = 0;
	friend std::ostream& operator<<(std::ostream& os, const ABC& rs);
};
class baseDMA : public ABC
{
public:
	//Ĭ�Ϲ��캯��
	baseDMA(const char* s = "null", int r = 0);
	//���ƹ��캯��
	baseDMA(const baseDMA& rs);
	virtual void View()const;
	//��Ԫ��������<<�����
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

//������: ��ʹ��new
class lackDMA : public ABC
{
private:
	enum
	{
		COL_LEN = 40
	};
	char color[COL_LEN];
public:
	lackDMA(const char* s = "none", const char* l = "null", int r = 0);
	//�̳���ĸ��ƹ��캯��
	lackDMA(const char* c, const baseDMA& hs);

	friend std::ostream& operator<<(std::ostream& os, const lackDMA& rs);
	virtual void View()const;
};

//������: ʹ��new
class hasDMA : public ABC
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	//�̳���ĸ��ƹ��캯��
	hasDMA(const char* s, const baseDMA& hs);
	hasDMA(const hasDMA& rs);
	~hasDMA();
	//���ظ�ֵ�����
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
	virtual void View()const;
}; 



/*
������
*/

class Port
{
private:
	char* brand;
	char style[20];
	int bottles;
public:
	Port(const char* br = "none", const char* s = "none", int b = 0);
	Port(const Port& p);
	virtual ~Port() { delete[]brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount()const { return bottles; }
	virtual void show()const;
	friend std::ostream& operator<<(std::ostream& os, const Port& p);
};

//������
class VintagePort :public Port
{
private:
	char* nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* br,const char* st, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort() { delete[]nickname; }
	VintagePort& operator=(const VintagePort& vp);
	void show()const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};

#endif

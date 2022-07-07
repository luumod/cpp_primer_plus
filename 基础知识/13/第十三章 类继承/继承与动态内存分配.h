


#ifndef DMA_H_
#define DMA_H_
#include <iostream>


class baseDMA 
{
private:
	char* label;
	int rating;
public:
	//默认构造函数
	baseDMA(const char* s = "null", int r = 0);
	//复制构造函数
	baseDMA(const baseDMA& rs);
	//虚析构函数
	virtual~baseDMA();
	//重载赋值运算符
	baseDMA& operator=(const baseDMA& rs);
	virtual void View()const;
	//友元函数重载<<运算符
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

//派生类: 不使用new
class lackDMA : public baseDMA
{
private:
	enum
	{
		COL_LEN = 40
	};
	char color[COL_LEN];
public:
	lackDMA(const char* s = "none", const char* l = "null", int r = 0);
	//继承类的复制构造函数
	lackDMA(const char* c, const baseDMA& hs);
	friend std::ostream& operator<<(std::ostream& os, const lackDMA& rs);
};

//派生类: 使用new
class hasDMA : public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	//继承类的复制构造函数
	hasDMA(const char* s,const baseDMA& hs);
	hasDMA(const hasDMA& rs);
	~hasDMA();
	//重载赋值运算符
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};
#endif // !DMA_H_

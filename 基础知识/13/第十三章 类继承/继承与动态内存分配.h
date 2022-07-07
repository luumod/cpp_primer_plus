


#ifndef DMA_H_
#define DMA_H_
#include <iostream>


class baseDMA 
{
private:
	char* label;
	int rating;
public:
	//Ĭ�Ϲ��캯��
	baseDMA(const char* s = "null", int r = 0);
	//���ƹ��캯��
	baseDMA(const baseDMA& rs);
	//����������
	virtual~baseDMA();
	//���ظ�ֵ�����
	baseDMA& operator=(const baseDMA& rs);
	virtual void View()const;
	//��Ԫ��������<<�����
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

//������: ��ʹ��new
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
	//�̳���ĸ��ƹ��캯��
	lackDMA(const char* c, const baseDMA& hs);
	friend std::ostream& operator<<(std::ostream& os, const lackDMA& rs);
};

//������: ʹ��new
class hasDMA : public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	//�̳���ĸ��ƹ��캯��
	hasDMA(const char* s,const baseDMA& hs);
	hasDMA(const hasDMA& rs);
	~hasDMA();
	//���ظ�ֵ�����
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};
#endif // !DMA_H_

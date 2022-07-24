

#ifndef ZHINENG_H_
#define ZHINENG_H_
#include <iostream>

class clever_ptr
{
private:
	int* n;
public:
	//���캯��
	clever_ptr(int* i) :n(i) {}
	//��������  �Զ�ɾ��
	~clever_ptr()
	{
		delete n;
	}

	int operator*();
	int operator[](int i);

	
	/*
	�����������
	*/
	friend std::ostream& operator<<(std::ostream& os,clever_ptr& n);
};

#endif // !ZHINENG_H_




#ifndef �Զ���_H_
#define �Զ���_H_
#include <iostream>

/*
��װһ�����õ���������
*/
class ������
{
private:
	int num;
public:
	//���캯��
	������(int n = 1) :num(n) {}
	//��������
	~������() {}
	//���ƹ��캯��
	������(const ������& n);
	void print()const;
	/*
	�������������
	*/
	������ operator+(const ������& n);
	������ operator-(const ������& n);
	������ operator*(const ������& n);
	������ operator/(const ������& n);
	������ operator=(const ������& n);

	������ operator+=(const ������& n);
	������ operator-=(const ������& n);
	������ operator*=(const ������& n);
	������ operator/=(const ������& n);

	friend ������ operator+(int i, const ������& n);
	friend ������ operator-(int i, const ������& n);
	friend ������ operator*(int i, const ������& n);
	friend ������ operator/(int i, const ������& n);

	/*
	�ⲿ���ʽӿ� 
	*/
	int GetNum()const
	{
		return num;
	}
	int& GetNum()
	{
		return num;
	}

};


#endif

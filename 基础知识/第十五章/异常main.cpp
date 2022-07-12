#include <iostream>
#include <cstdlib>
#include <cmath>
#include "�쳣.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
abort()����
*/
#if 0
double hmean(double a, double b);

int main()
{
	double x, y, z;

	cout << "������������ �������ƽ����: ";
	while (cin >> x >> y)
	{
		z = hmean(x, y);
		cout << z << endl;
		cout << "������������ �������ƽ����: ";
	}
	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
	{
		cout << "����! " << endl;
		std::abort();
	}
	return 2.0 * a * b / (a + b);
}
#endif 


/*
���ش�����
*/
#if 0
bool hmean(double a, double b,double* ans);

int main()
{
	double x, y, z;

	cout << "������������ �������ƽ����: ";
	while (cin >> x >> y)
	{
		if (hmean(x, y, &z))
		{
			cout << z << endl;
		}
		else
		{
			cout << "��������! " << endl;
		}
		cout << "������������ �������ƽ����: ";
	}
	return 0;
}
bool hmean(double a, double b,double* ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans= 2.0 * a * b / (a + b);
		return true;
	}
}

#endif


/*
�쳣����: 
	1. �����쳣
	2. ʹ�ô�����򲶻��쳣
	3. ʹ��try��
*/

#if 0

double hmean(double a, double b);

int main()
{
	double x, y, z;

	cout << "������������ �������ƽ����: ";
	while (cin >> x >> y)
	{
		try			//��ʼtry
		{
			z = hmean(x, y);
		}
		catch (const char* s)	//�쳣����
		{
			//���쳣���д���
			cout << s << endl;
			cout << "������������ �������ƽ����: ";
			continue;
		}
		cout << z << endl;
		cout << "������������ �������ƽ����: ";
	}
	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
	{
		//�����쳣�ַ���
		throw "�������� : a = -b ��������! ";	//������ִ��return 
	}
	return 2.0 * a * b / (a + b);
}

#endif // 1

/*
���е��쳣����
*/

#if 0
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
	double x, y, z;
	cout << "��������������: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << z << endl;
			cout << gmean(x, y) << endl;
			cout << "��������������: ";
		}
		catch (bad_hmean& bg)
		{
			//���������������
			bg.mesg();			//ʹ�ù��з��������ַ���
			cout << "Try again: " << endl;
			continue;
		}
		catch (bad_gmean& hg)
		{
			//���������ֱ��break
			cout << hg.mesg();	//��ӡ�ַ���
			cout << "����! " << endl;
			break;
		}
	}
	cout << "Bye! " << endl;
	return 0;
}
double hmean(double a, double b)
{
	/*
	�������ƽ����
	*/
	if (a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	/*
	������˵�ƽ����
	*/
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}
	return std::sqrt(a*b);
}

#endif // 1


#if 0
int main()
{
	double vals[12] =
	{
		1220,1100,1122,2212,1232,2334,
		2884,2393,3302,2922,3002,3544,
	};

	double vals2[12] =
	{
		12,11,22,31,32,34,
		28,29,33,29,32,35
	};

	Sales sales1(2011, vals, 12);
	LabeledSales sales2("Blogstaer", 2012, vals, 12);

	cout << "first try block: \n";
	try
	{
		int i;
		cout << "Year= " << sales1.Year() << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << sales1[i] << " ";
			if (i & 6 == 5)
			{
				cout << endl;
			}
		}
		cout << "Year= " << sales2.Year() << endl;
		cout << "Label= " << sales2.Label() << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << sales2[i] << " ";
			if (i & 6 == 5)
			{
				cout << endl;
			}
		}
		cout << "End of try block 1.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad_index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}

	cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 999;
		sales1[20] = 6666;	//�����±�Խ�� 
		cout << "End of try block 2.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad_index: " << bad.bi_val() << endl;
	}
	//���� bad_index�Ĵ��������
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "Done! " << endl;

	return 0;
}
#endif 




/*
�����쳣
	
δ�����쳣
*/
void MyQuit()
{
	cout << "Terminating due to uncatught exceptionn\n";
	exit(5);
}
int main()
{
	set_terminate(MyQuit);

	return 0;
}
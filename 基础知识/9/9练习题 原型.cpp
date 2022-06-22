#include <iostream>
#include "4.h"

////���� ��һ���汾
//void setgolf(golf& g, const char* name, int hc)
//{
//	strcpy(g.fullname, name);
//	g.handicap = hc;
//}
//
////���� �ڶ����汾
//int setgolf(golf& g)
//{
//	//��������Ϊ�� �򷵻� 0
//	std::cout << "����������:";
//	std::cin.getline(g.fullname, 40);	
//	if (strcmp(g.fullname, "\0") == 0)
//	{
//		//����Ϊ�� ֹͣ
//		return 0;
//	}
//	std::cout << "������ȼ�:";
//	//������������
//	while (!(std::cin >> g.handicap))
//	{
//		std::cin.clear();
//		while (std::cin.get() != '\n')
//			continue;
//		std::cout << "please enter again:" << std::endl;
//	}
//	//�������Ļس�
//	std::cin.get();
//	return 1;
//}
//
//void handicap(golf& g, int hc)
//{
//	std::cout << "g.hc: " << g.handicap << std::endl;
//}
//void showgolf(const golf& g)
//{
//	using std::cout;
//	using std::cin;
//	using std::endl;
//	cout << "������ĳ�Ա��:";
//	cout << "����: " << g.fullname << " ";
//	cout << "�ȼ�: " << g.handicap << endl;
//}
//


namespace SALES
{
    void setSales(Sales& s, const double ar[], int n)
    {
        double total = 0.0;
        double max = ar[0];
        double min = ar[0];
        for (int i = 1; i < n; i++)
        {
            s.sales[i] = ar[i];
            total += ar[i];
            if (ar[i] > max)
            {
                max = ar[i];
            }
            if (ar[i] < min)
            {
                min = ar[i];
            }
        }
        s.min = min;
        s.max = max;
        s.average = total / n;
        return;
    }

    void setSales(Sales& s)
    {
        using namespace std;
        int len;
        cout << "Enter the length of sales(<= 4 and > 0): ";
        while (!(cin >> len) || len > 4 || len <= 0)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please enter a number(<= 4 and > 0): ";
        }
        double* temp = new double[len];
        cout << "Please enter the sales:" << endl;
        for (int i = 0; i < len; i++)
        {
            cout << "Please enter the content #" << i + 1 << ": ";
            while (!(cin >> temp[i]))
            {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "Please enter a number: ";
            }
        }
        setSales(s, temp, len);
        delete[] temp;
        return;
    }

    void showSales(const Sales& s)
    {
        std::cout << "Sales average: " << s.average << std::endl;
        std::cout << "Sales max: " << s.max << std::endl;
        std::cout << "Sales min: " << s.min << std::endl;
        return;
    }
}
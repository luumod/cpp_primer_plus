
#include <iostream>
#include "9��ϰ�� ԭ��.cpp"
//3.
//int main()
//{
//	double x;
//	std::cout << "Enter value:";
//	while (!(std::cin >> x))
//	{
//		std::cout << "Bad input,plaease enter again:";
//		std::cin.clear();
//		while (std::cin.get() != '\n')
//			continue;
//	}
//	std::cout << "Value= " << x << std::endl;
//	return 0;
//}


//4.
//int main()
//{
//	using std::cout;
//	using std::cin;
//	using std::endl;
//	double x;
//	cout << "Enter value:";
//	while (!(cin >> x))
//	{
//		cout << "Bad input,plaease enter again:";
//		cin.clear();
//		while (cin.get() != '\n')
//			continue;
//	}
//	cout << "Value= " << x << endl;
//	return 0;
//}

//const int SIZE = 5;
//int main()
//{
//	int hc = 0;
//	int fg = 0;
//
//	int i = 0;
//	golf andy[SIZE];
//	for (int i = 0; i < SIZE; i++)
//	{
//		if (setgolf(andy[i]))//����������
//		{
//			//����ɹ�
//			hc++;
//		}
//		else
//			break;
//	}
//	for (int i = 0; i < hc; i++)
//	{
//		showgolf(andy[i]);
//	}
//	return 0;
//}







//2.
//void strcount(std::string str);
//int main()
//{
//	using namespace std;
//	/*
//	ʹ��cin.get����char�ַ����ķ��� �����˳�������
//	*/
//	string str;
//	char next;
//	cout << "�����ַ���(����ո��˳�): " << endl;
//	while ( getline(cin, str))
//	{
//		if (str == "\n")
//			break;
//		strcount(str);
//		cout << "��������(����ո��˳�): " << endl;
//	}
//	return 0;
//}
//void strcount(std::string str)
//{
//	using namespace std;
//	static int total = 0;
//	int count = 0;
//	cout << str << endl;
//	count = str.size();
//	total += count;
//	cout << "count: "<<count<< endl;
//	cout << "total: " << total << endl;
//}




//3.
//const int SIZE = 60;
//struct chaff
//{
//	char dross[20];
//	int slag;
//};
//char ar[SIZE];
//int main()
//{
//	//new��λ�����
//	chaff* str = new (ar) chaff[2]{ {"ylh",50 },{"wlh",40} };
//	std::cout << (void*)ar << "  " << str << std::endl;
//	for (int i = 0; i < 2; i++)
//	{
//		std::cout << "����: " << str[i].dross << "; ����: " << str[i].slag << std::endl;
//	}
//	/*
//	00007FF75777D170  00007FF75777D170
//	����: ylh; ����: 50
//	����: wlh; ����: 40
//	*/
//	return 0;
//}



//4.

int main()
{
    using namespace SALES;
    Sales objects[2];
    const double temp[4] = { 1.0, 2.0, 3.0, 4.0 };

    setSales(objects[0]);
    setSales(objects[1], temp, 4);
    showSales(objects[0]);
    showSales(objects[1]);
    std::cout << "Bye." << std::endl;

    return 0;
}

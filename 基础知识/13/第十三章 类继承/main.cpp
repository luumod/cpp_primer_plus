
#include <iostream>
#include "��ϰ��.h"

//void Bravo(const Cd& disk);
//int main()
//{
//	using std::cout;
//	using std::cin;
//	using std::endl;
//
//	Cd c1{ "������","��˧��",66,11.11 };
//	Classic c2{ "������","Ҳ��˧��","�Ź�",66,33.33 };
//
//	Cd* pcd = &c1;
//	
//	cout << "Using object directly: " << endl;
//	c1.Report();
//	c2.Report();
//
//	cout << "Using type cd* pointer to object: " << endl;
//	pcd->Report();
//	
//	cout << "function: " << endl;
//	Bravo(c1);
//	Bravo(c2);
//
//
//	cout << "Testing assignment: " << endl;
//	Classic copy;
//	copy = c2;
//	copy.Report();
//
//	return 0;
//}
//void Bravo(const Cd& disk)
//{
//	disk.Report();
//}


/*
������
*/
//const int SIZE = 5;
//int main()
//{
//	using std::cout;
//	using std::cin;
//	using std::endl;
//
//	ABC* destion[SIZE];
//	int choice = 0;
//	char label[50];
//	int rating;
//	char color[50];
//	char style[50];
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		cout <<endl<< "�������" << i + 1 << "������Ԫ������: 1.baseDMA 2.lackDMA 3.hasDMA";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << "����label: ";
//			cin >> label;
//			cout << "����rating: ";
//			cin >> rating;
//			while (cin.get() != '\n')
//				;
//			destion[i] = new baseDMA{label,rating};
//			break;
//		case 2:
//			cout << "����label: ";
//			cin >> label;
//			cout << "����rating: ";
//			cin >> rating;
//			cout << "����color: ";
//			cin >> color;
//			while (cin.get() != '\n')
//				;
//			destion[i] = new lackDMA{ label,color,rating };
//			break;
//		case 3:
//			cout << "����label: ";
//			cin >> label;
//			cout << "����rating: ";
//			cin >> rating;
//			cout << "����style: ";
//			cin >> style;
//			while (cin.get() != '\n')
//				;
//			destion[i] = new lackDMA{ label,style,rating };
//			break;
//		default:
//			break;
//		}
//	}
//	cout << "�������! " << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//		destion[i]->View();
//		cout << endl;
//	}
//	return 0;
//}



/*
������
*/
int main()
{
	using std::cout;
	using std::endl;
	Port one;
	Port two{ "������","��˧��",666 };
	Port temp;
	temp = two;
	VintagePort ro;
	VintagePort po{ "������","С˧��",999,"�ٺٺ�",333 };
	VintagePort temp2;
	VintagePort copy{ po};
	temp2 = po;


	cout << "Port: " << endl;
	one.show();
	two.show();

	cout << "VIntagePort: " << endl;
	ro.show();
	po.show();

	cout << "Temp: " << endl;
	temp.show();
	temp2.show();
	
	cout << "<< : " << endl;
	cout << temp;
	cout << temp2;

	cout << "+= -=: " << endl;
	temp -= 40;
	temp2 += 90;
	temp.show();
	temp2.show();

	cout << "--------" << endl;
	copy.show();
	return 0;
}
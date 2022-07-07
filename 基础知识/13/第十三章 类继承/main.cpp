
#include <iostream>
#include "练习题.h"

//void Bravo(const Cd& disk);
//int main()
//{
//	using std::cout;
//	using std::cin;
//	using std::endl;
//
//	Cd c1{ "于良浩","是帅哥",66,11.11 };
//	Classic c2{ "王吉虎","也是帅哥","才怪",66,33.33 };
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
第三题
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
//		cout <<endl<< "请输入第" << i + 1 << "个数组元素类型: 1.baseDMA 2.lackDMA 3.hasDMA";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << "输入label: ";
//			cin >> label;
//			cout << "输入rating: ";
//			cin >> rating;
//			while (cin.get() != '\n')
//				;
//			destion[i] = new baseDMA{label,rating};
//			break;
//		case 2:
//			cout << "输入label: ";
//			cin >> label;
//			cout << "输入rating: ";
//			cin >> rating;
//			cout << "输入color: ";
//			cin >> color;
//			while (cin.get() != '\n')
//				;
//			destion[i] = new lackDMA{ label,color,rating };
//			break;
//		case 3:
//			cout << "输入label: ";
//			cin >> label;
//			cout << "输入rating: ";
//			cin >> rating;
//			cout << "输入style: ";
//			cin >> style;
//			while (cin.get() != '\n')
//				;
//			destion[i] = new lackDMA{ label,style,rating };
//			break;
//		default:
//			break;
//		}
//	}
//	cout << "输入完毕! " << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//		destion[i]->View();
//		cout << endl;
//	}
//	return 0;
//}



/*
第四题
*/
int main()
{
	using std::cout;
	using std::endl;
	Port one;
	Port two{ "于良浩","大帅哥",666 };
	Port temp;
	temp = two;
	VintagePort ro;
	VintagePort po{ "王吉虎","小帅哥",999,"嘿嘿嘿",333 };
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
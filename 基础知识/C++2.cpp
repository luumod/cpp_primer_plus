#include <iostream>
//加入以下指令后就不必加上std::前缀
//using namespace std;	//using编译指令
//int main(void)
//{
//	//允许使用C语言的换行符
//	cout << "Welcome to C++\n" << endl << "abcd" << endl << "woaiuin" << endl;
//
//	return 0;
//}
//
//int main(void)
//{
//	using namespace std;
//	cout << "Welcome to C++" << endl;
//	return 0;
//}

//变量
//using namespace std;
//int main(void)
//{
//	//尽可能在首次使用变量前声明他
//	int cat = 25;
//	cout << "cat=";
//	cout << cat << endl;
//	cat -= 1;
//	cout << "cat=" << cat << endl;
//	//C++可以使用连续运算符
//	int a, b, c;
//	a = b = c = 6;
//	cout << "a=" << a << " b=" << b << " c=" << c << endl;
//	return 0;
//}


//cin输入函数
//int main(void)
//{
//	using namespace std;
//	int num;
//	cout << "请输入数字:";
//	cin >> num;
//	cout << "num=" << num << endl;
//
//	return 0;
//}
int stonetotal(int);
int main(void)
{
	/*using namespace std;
	int stone;
	cout << "请输入石头的重量:";
	cin >> stone;
	int pont = stonetotal(stone);
	cout<<"重量: "<<pont<<endl;*/
	using std::cout;

	return 0;
}
int stonetotal(int n)
{
	return 14 * n;
}
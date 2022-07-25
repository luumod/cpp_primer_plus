#include <iostream>
#include <exception>
using namespace std;
/*
流状态： 设置 1  清除 0
	出错则返回 1
	eofbit
	badbit
	failbit

	eof
	bad
	fail
	rastate  返回流状态
	exceptions
	clear
	setstate
*/

#if 0

int main()
{
	cin.exceptions(ios_base::failbit);
	cout << "输入数字: ";
	int input;
	int sum = 0;
	
	try
	{
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure& bf)
	{
		cout << bf.what() << endl;
		cout << "O! the horror!\n";
	}
	/*
	如果输入错误  将导致下一次输入无法进行
	*/
	
	/*cout << "输入: ";
	cin >> a;
	cout << a << endl;*/
	int a;
	cin.clear();		//重置输入流状态为良好
	while (!isspace(cin.get()))
		;
	cin >> a;

	cout << "您的最后一次输入: " << input << endl;
	cout << "Sum= " << sum << endl;
	return 0;
}

#elif 1

/*
>>					//跳过空白
cin.get(char*)		//保留空白
cin.get()			//保留空白
*/

#endif // 1

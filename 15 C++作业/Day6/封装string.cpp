
#include "string.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	String str1;
	String str2("ILoveyou");
	String str3 = String(str2);
	String str4 = "IMiss";
	String str5;
	str5 = " lxy";
	String str6{ str5 };
	String result;
	result=str5+str4;
	String input;

	std::cin >> input;
	std::cout <<"input: "<< input << endl;

	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << str3 << endl;
	cout << "str4: " << str4 << endl;
	cout << "str5: " << str5 << endl;
	cout << "str6: " << str6 << endl;
	cout << "result: " << result << endl;
	
	//size()函数
	//empty()函数
	if (!str2.empty())
	{
		for (int i = 0; i < str2.size(); i++)
		{
			//4.能够下标访问
			cout << str2[i] << " ";
		}
	}	
	cout << endl;
	//增加c_str()
	const char* s1 = str2.c_str();
	cout << s1 << endl;

	//data()函数实现
	const char* s2 = str2.data();
	cout << s2 << endl;

	if (str2 > str3)
	{
		cout << "str2 比 str3大" << endl;
	}
	else
	{
		cout << "str2 比 str3小" << endl;
	}
	return 0;
}
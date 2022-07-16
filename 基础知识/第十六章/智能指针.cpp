#include <iostream>
#include <string>
#include <memory>

/*
智能指针  模板类
	auto_ptr
	unique_ptr
	shared_ptr
如果将new返回的地址赋给这些对象 无需记住稍后释放内存; 智能指针过期时,这些内存将被自动释放
*/
#if 0
class Report
{
private:
	std::string str;
public:
	Report(const std::string s) :str(s)
	{
		std::cout << "Object created.\n";
	}
	~Report()
	{
		std::cout << "Object deleted.\n";
	}
	void comment()const
	{
		std::cout << str << "\n";
	}
};

int main()
{
	//自动释放所处的内存区块
	{
		std::auto_ptr<Report> ps(new Report("Using auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> pw(new Report("Using shared_ptr"));
		pw->comment();
	}
	{
		std::unique_ptr<Report> pn(new Report("Using unique_ptr"));
		pn->comment();
	}

	return 0;
}

#elif 0
/*
不适用于auto_ptr
*/

int main()
{
	using namespace std;
#if 0
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("我是第一")),
		auto_ptr<string>(new string("我是第二")),
		auto_ptr<string>(new string("我是第三")),
		auto_ptr<string>(new string("我是第四")),
		auto_ptr<string>(new string("我是第五")),
	};
	auto_ptr<string> pwin;
	//将其所有权转换为pwin
	pwin = films[2];
	cout << "-----------------" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << *films[i] << endl;
	}
	cout << "Last: " << *pwin << endl;
	cin.get();
#else
	/*
	使用shared_ptr 来替代 auto_ptr 
	*/
	shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("我是第一")),
		shared_ptr<string>(new string("我是第二")),
		shared_ptr<string>(new string("我是第三")),
		shared_ptr<string>(new string("我是第四")),
		shared_ptr<string>(new string("我是第五")),
	};
	shared_ptr<string> pwin;
	//将其所有权转换为pwin
	pwin = films[2];
	cout << "-----------------" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << *films[i] << endl;
	}
	cout << "Last: " << *pwin << endl;
	cin.get();
	#endif
	return 0;
}

#elif 1

int main()
{
	using namespace std;
	unique_ptr<string> temp(new string("unique"));
	unique_ptr<string> p;
	//p = temp;			//发出警告
	return 0;
}


/*
选择 :
	使用多个指向同一个对象的指针 : shared_ptr
	函数使用new分配内存并且返回该指针 : unique_ptr
*/
#endif

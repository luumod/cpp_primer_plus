#include <iostream>
#include <string>
#include <memory>

/*
����ָ��  ģ����
	auto_ptr
	unique_ptr
	shared_ptr
�����new���صĵ�ַ������Щ���� �����ס�Ժ��ͷ��ڴ�; ����ָ�����ʱ,��Щ�ڴ潫���Զ��ͷ�
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
	//�Զ��ͷ��������ڴ�����
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
��������auto_ptr
*/

int main()
{
	using namespace std;
#if 0
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("���ǵ�һ")),
		auto_ptr<string>(new string("���ǵڶ�")),
		auto_ptr<string>(new string("���ǵ���")),
		auto_ptr<string>(new string("���ǵ���")),
		auto_ptr<string>(new string("���ǵ���")),
	};
	auto_ptr<string> pwin;
	//��������Ȩת��Ϊpwin
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
	ʹ��shared_ptr ����� auto_ptr 
	*/
	shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("���ǵ�һ")),
		shared_ptr<string>(new string("���ǵڶ�")),
		shared_ptr<string>(new string("���ǵ���")),
		shared_ptr<string>(new string("���ǵ���")),
		shared_ptr<string>(new string("���ǵ���")),
	};
	shared_ptr<string> pwin;
	//��������Ȩת��Ϊpwin
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
	//p = temp;			//��������
	return 0;
}


/*
ѡ�� :
	ʹ�ö��ָ��ͬһ�������ָ�� : shared_ptr
	����ʹ��new�����ڴ沢�ҷ��ظ�ָ�� : unique_ptr
*/
#endif

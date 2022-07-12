
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using std::cout;
using std::cin;
using std::endl;
using std::string;


/*
RTTI:
	运行阶段类型识别

	dynameic_cast
	typeid
	type_info
*/

//dynamic_cast  强制类型转换

#if 0

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) :hold(h) {}
	/*
	定义了一个虚函数 其他类也都重新定义了该虚函数
	*/
	virtual void Speak()const
	{
		cout << "I am a grand class!\n";
	}
	virtual int Value()const
	{
		return hold;
	}
};


class Superb:public Grand
{
public:
	Superb(int h = 0) :Grand(h) {}
	void Speak()const
	{
		cout << "I am a Super class!\n";
	}
	/*
	一个新的虚函数
	*/
	virtual void Say()const
	{
		cout << "I hold the superb value of " << Value() << "!\n";
	}

};

class Magnifiaent :public Superb
{
private:
	char ch;
public:
	Magnifiaent(int h = 0, char c = 'A')
		:Superb(h), ch(c) {}
	void Speak()const
	{
		cout << "I am a magnifient class!\n";
	}
	void Say()const
	{
		cout << "I hold the character " << ch << " and the intger " << Value() << "!\n";
	}
};

Grand* Getone();

int main()
{
	std::srand(std::time(0));
	Grand* pG;
	Superb* pS;
	Magnifiaent* pM;
	for (int i = 0; i < 5; i++)
	{
		//基类指针可以指向派生类的指针或引用
		pG = Getone();	//随机创建一个对象
		pG->Speak();	//虚函数 可以自动调用对应版本的Speak函数
		/*
		类型转换成功  pS为非零; 失败 则pS为零

		用于引用: bad_cast
			try
			{
				Superb& rs=dynamic_cast<Superb&> (rg);
			}
			catch(bad_cast)
			{
				...
			}
		*/
		if (pS = dynamic_cast<Superb*>(pG))
		{
			/*
				为什么要转换为Superb ?
			转换为Superb 可以使得其派生类也可以调用在Superb类中定义的虚函数
			基类指针可以指向派生类的指针  因而也可以调用派生类的函数
			*/
			pS->Say();	
		}
		/*if (pM = dynamic_cast<Magnifiaent*>(pG))
		{
			pM->Say();		//只能调用Magnifient类的Say  不能调用上一级的虚函数Say
		}*/
	}

	return 0;
}

Grand* Getone()
{
	Grand* p;
	switch (std::rand() % 3)
	{
	case 0:p = new Grand(std::rand() % 100);
		break;
	case 1:p = new Superb(std::rand() % 100);
		break;
	case 2:p = new Magnifiaent(std::rand() % 100,
		'A' + std::rand() % 26);
		break;
	}
	return p;
}


#endif



//typeid运算符 和 type_info 类

/*
typeid 运算符使得能够确定两个对象是否为同种类型，接受两种参数:
	类名
	结果为对象的表达式
返回一个type_info对象的引用 
*/



#if 0
class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) :hold(h) {}
	virtual void Speak()const
	{
		cout << "I am a grand class!\n";
	}
	virtual int Value()const
	{
		return hold;
	}
};


class Superb :public Grand
{
public:
	Superb(int h = 0) :Grand(h) {}
	void Speak()const
	{
		cout << "I am a Super class!\n";
	}
	virtual void Say()const
	{
		cout << "I hold the superb value of " << Value() << "!\n";
	}
};

class Magnifiaent :public Superb
{
private:
	char ch;
public:
	Magnifiaent(int h = 0, char c = 'A')
		:Superb(h), ch(c) {}
	void Speak()const
	{
		cout << "I am a magnifient class!\n";
	}
	void Say()const
	{
		cout << "I hold the character " << ch << " and the intger " << Value() << "!\n";
	}
};

Grand* Getone();

int main()
{
	std::srand(std::time(0));
	Grand* pG;
	Superb* pS;
	Magnifiaent* pM;
#if 1	//dynamic_cast方法
	for (int i = 0; i < 5; i++)
	{
		//基类指针可以指向派生类的指针或引用
		pG = Getone();	//随机创建一个对象
		cout << "Now process type " << typeid(*pG).name() << endl;
		pG->Speak();	//虚函数 可以自动调用对应版本的Speak函数
		/*
		如果 pG 指向的是一个Magnificent的对象 则返回true
		*/
		if ((typeid(Magnifiaent) == typeid(*pG)))
		{
			cout << "Yes, you are really magnificent.\n";
		}
		if (pS = dynamic_cast<Superb*>(pG))
		{
			pS->Say();
		}
	}
#else	//typeid 方法
	for (int i = 0; i < 5; i++)
	{
		//基类指针可以指向派生类的指针或引用
		pG = Getone();	//随机创建一个对象
		/*
		如果 pG 指向的是一个Magnificent的对象 则返回true
		*/
		if ((typeid(Magnifiaent) == typeid(*pG)))
		{
			//Magnifiaent类型
			pM = (Magnifiaent*)pG;
			pM->Speak();
			pM->Say();
		}
		else if (typeid(Superb)==typeid(*pG))
		{
			//Superb类型
			pS = (Superb*)pG;
			pS->Speak();
			pS->Say();
		}
		else
		{
			//基类类型
			pG->Speak();
		}
	}
#endif

	return 0;
}

Grand* Getone()
{
	Grand* p;
	switch (std::rand() % 3)
	{
	case 0:p = new Grand(std::rand() % 100);
		break;
	case 1:p = new Superb(std::rand() % 100);
		break;
	case 2:p = new Magnifiaent(std::rand() % 100,
		'A' + std::rand() % 26);
		break;
	}
	return p;
}


#endif



/*
类型转换运算符:
	dynamic_cast
	const_cast;
	static_cast
	reinterpret_cast
*/

//dynamic_cast: 使得能够在类层次结构中进行向上转换

//const_cast:	改变值为const或者volatile的变量

void change(const int* pt, int n);
int main()
{
	int pop1 = 10000;
	const int pop2 = 2000;

	cout << "pop1 pop2: " << pop1 << "," << pop2 << endl;
	change(&pop1, 1000);
	change(&pop2, 1000);
	cout << "pop1 pop2: " << pop1 << "," << pop2 << endl;

	return 0;
}
void change(const int* pt, int n)
{
	int* pc;
	//创建一个新的int* 指针
	//让pc指向删除const的int* 的pt 因此相当于pt变成了可以修改的值
	/*
	只能用于修改不是const的值 当值本身就是const 则无法实现
	*/
	pc = const_cast<int*>(pt);
	*pc += n;
}

//static_cast 转换

//reinterpret_cast 
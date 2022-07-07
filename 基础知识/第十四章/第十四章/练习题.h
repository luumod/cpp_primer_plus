
#ifndef 编程练习_H_
#define 编程练习_H_
#include <valarray>
#include <string>
using std::cin;
using std::cout;
using std::endl;


/*
包含  葡萄酒
*/
#if 0
template <typename T1,typename T2>
class Pair
{
private:
	T1 year;
	T2 bottles;
public:
	Pair() {}
	Pair(const T1& y,const  T2& b)
		:year(y), bottles(b) {}
	void Set(const T1& y, const T2& b);
	int Sum();
	void Show(int n)const;
};



template<typename T1, typename T2>
inline void Pair<T1, T2>::Set(const T1& y, const T2& b)
{
	//此时 year和bottles类似于 数组类型
	year = y;
	bottles = b;
}

template<typename T1, typename T2>
inline int Pair<T1, T2>::Sum()
{
	// std::valarray<int>.sum()
	return bottles.sum();
}

template<typename T1, typename T2>
inline void Pair<T1, T2>::Show(int n) const
{
	for (int i = 0; i < n; i++)
	{
		cout << year[i] << "\t" << bottles[i] << endl;
	}
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	std::string label;				//名称
	PairArray year_and_bottles;		//年份和瓶数
	int year;						//存储的年份
public:
	//默认构造函数
	Wine();
	//非默认构造函数
	Wine(const char* l, int y, const int* yr, const int* bot);
	Wine(const char* l, int y);
	~Wine(){}
	void GetBottles();
	std::string& Label();
	int sum();
	void Show()const;
};

#endif

/*
私有继承完成第一题
*/
#if 0

template <typename T1, typename T2>
class Pair
{
private:
	T1 year;
	T2 bottles;
public:
	Pair() {}
	Pair(const T1& y, const  T2& b)
		:year(y), bottles(b) {}
	void Set(const T1& y, const T2& b);
	int Sum();
	void Show(int n)const;
};



template<typename T1, typename T2>
inline void Pair<T1, T2>::Set(const T1& y, const T2& b)
{
	//此时 year和bottles类似于 数组类型
	year = y;
	bottles = b;
}

template<typename T1, typename T2>
inline int Pair<T1, T2>::Sum()
{
	// std::valarray<int>.sum()
	return bottles.sum();
}

template<typename T1, typename T2>
inline void Pair<T1, T2>::Show(int n) const
{
	for (int i = 0; i < n; i++)
	{
		cout << year[i] << "\t" << bottles[i] << endl;
	}
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine: private std::string,private PairArray
{
private:
	//std::string label;				//名称
	//PairArray year_and_bottles;		//年份和瓶数
	int year;						//存储的年份
public:
	//默认构造函数
	Wine();
	//非默认构造函数
	Wine(const char* l, int y, const int* yr, const int* bot);
	Wine(const char* l, int y);
	~Wine() {}
	void GetBottles();
	std::string& Label();
	int sum();
	void Show()const;
};

#endif


/*
队列
*/




#if 0

class Worker
{
private:
	std::string fullname;
	long id;

public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const std::string& s, long n) : fullname(s), id(n) {}
	~Worker();
	void Set();
	void Show() const;
};



template <typename T>
class QueueTp
{
private:
	enum { MAX = 10 };
	struct Node
	{
		struct Node* next;
		T item;
	};
	Node* pHead;
	int items;
	const int size;
public:
	QueueTp(int n=MAX);
	~QueueTp();
	bool isempty();
	bool isfull();
	bool push(T& item);
	bool pop(T& item);
	int queuecount()const;
};

//初始化链表
template<typename T>
inline QueueTp<T>::QueueTp(int n)
	:size(n)
{
	pHead = nullptr;
	items = 0;
}

//析构函数  释放内存
template<typename T>
inline QueueTp<T>::~QueueTp()
{
	Node* pTemp;
	while (pHead)
	{
		pTemp = pHead->next;
		delete pHead;
		pHead = pTemp;
	}
}

template<typename T>
inline bool QueueTp<T>::isempty()
{
	return items == 0;
}

template<typename T>
inline bool QueueTp<T>::isfull()
{
	return items == MAX;
}

template<typename T>
inline bool QueueTp<T>::push(T& item)
{
	if (isfull())
	{
		return false;
	}
	Node* pNew = new Node;
	pNew->next = nullptr;
	pNew->item = item;
	items++;		//节点个数增加
	if (pHead == nullptr)
	{
		//是头节点
		pHead = pNew;
	}
	else
	{
		//插入到链表尾部
		Node* pTemp = pHead;
		while (pTemp->next)
		{
			pTemp = pTemp->next;
		}
		pTemp->next = pNew;
	}
	return true;
}

template<typename T>
inline bool QueueTp<T>::pop(T& item)
{
	if (isempty())
	{
		return false;
	}
	else
	{
		item = pHead->item;
		Node* pTemp = pHead;
		pHead = pHead->next;
		delete pTemp;
		items--;
		if (items == 0)
		{
			pHead = nullptr;
		}
		return true;
	}
}

template<typename T>
inline int QueueTp<T>::queuecount() const
{
	return items;
}

#endif

/*
栈
*/
#if 0
class Worker
{
private:
	std::string fullname;
	long id;

public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const std::string& s, long n) : fullname(s), id(n) {}
	~Worker();
	void Set();
	void Show() const;
};



template <typename T>
class pStack
{
private:
	enum { MAX = 10 };
	struct Node
	{
		struct Node* next;
		T item;
	};
	Node* pHead;
	int items;
	const int size;
public:
	pStack(int n = MAX);
	~pStack();
	bool isempty();
	bool isfull();
	bool push(T& item);
	bool pop(T& item);
	int queuecount()const;
	void show()const;
};

//初始化链表
template<typename T>
inline pStack<T>::pStack(int n)
	:size(n)
{
	pHead = nullptr;
	items = 0;
}

//析构函数  释放内存
template<typename T>
inline pStack<T>::~pStack()
{
	Node* pTemp;
	while (pHead)
	{
		pTemp = pHead->next;
		delete pHead;
		pHead = pTemp;
	}
}

template<typename T>
inline bool pStack<T>::isempty()
{
	return items == 0;
}

template<typename T>
inline bool pStack<T>::isfull()
{
	return items == MAX;
}

//入栈
template<typename T>
inline bool pStack<T>::push(T& item)
{
	if (isfull())
	{
		return false;
	}
	//创建新的节点
	Node* pNew = new Node;
	pNew->item = item;
	pNew->next = nullptr;
	items++;
	//如果链表为空
	if (pHead == nullptr)
	{
		pHead = pNew;
	}
	//如果不为空
	else
	{
		Node* pTemp = pHead;
		while (pTemp->next)
		{
			pTemp= pTemp->next;
		}
		pTemp->next = pNew;	//节点连接
	}
	return true;
}

//出栈
template<typename T>
inline bool pStack<T>::pop(T& item)
{
	if (isempty())
	{
		return false;
	}
	else
	{
		Node* pTail=pHead;				//链表最后一个节点
		while (pTail->next)
		{
			pTail = pTail->next;
		}
		//后进先出  先删除尾部节点
		if (pHead==pTail)			//首节点等于尾节点 只有一个节点
		{
			//如果只有一个节点
			item = pHead->item;
			pHead = nullptr;
			items--;
		}
		else
		{
			Node* pPreTail = pHead;
			while (pPreTail->next!=pTail)		//找到待删除结点的前一个节点
			{
				pPreTail = pPreTail->next;
			}
			item = pTail->item;
			pPreTail->next = nullptr;
			items--;
		}
		return true;
	}
}

template<typename T>
inline int pStack<T>::queuecount() const
{
	return items;
}

template<typename T>
inline void pStack<T>::show() const
{
	Node* pTemp = pHead;
	while (pTemp)
	{
		cout << pTemp->item << " ";
		pTemp = pTemp->next;
	}
	cout << endl;
}

#endif 


/*
第四题
*/
#if 0
using std::string;

class Person
{
private:
	string fname;
	string lname;
protected:
	/*
	虚保护方法获取基类成员信息, 使得派生类可以间接访问;
	*/
	virtual void Data()const;		//显式基类的信息
	virtual void Get();				//输入信息
public:
	Person(const string& fn = "none", const string& ln = "none")
		:fname(fn), lname(ln) {}
	Person(const Person& p)
		:fname(p.fname), lname(p.lname) {}
	virtual ~Person() = 0;
	//显示信息
	virtual void Show()const = 0;	//纯虚函数
	//设置信息
	virtual void Set() = 0;
};

//虚基类
class GunsLinger : virtual public Person
{
private:
	int num;	//刻痕数
protected:
	void Data()const;
	void Get();			//重写num成员数据
public:
	GunsLinger(const string& fn = "none", const string& ln = "none", int number = 0)
		:Person(fn, ln), num(number) {}
	GunsLinger(const Person& p, int number)
		:Person(p), num(number) {}
	double Draw()const;	//返回枪手的把枪时间
	void Show()const;
	void Set();
};

class PokerPlayer :virtual public Person
{
protected:
	void Data()const;
public:
	PokerPlayer(const Person& p)
		:Person(p) {}
	PokerPlayer(const string& fn = "none", const string& ln = "none", int h = 0, int n = 2)
		:Person(fn, ln) {}
	double Draw()const;
	void Show()const;
	void Set();
};

class BadDude :public GunsLinger, public PokerPlayer
{
protected:
	void Data()const;
	void Get();
public:
	BadDude(const string& fn = "none", const string& ln = "none", int number = 0, int h = 0, int n = 2)
		:Person(fn, ln), GunsLinger(fn, ln, number), PokerPlayer(fn, ln, h, n) {}
	BadDude(const GunsLinger& G, const PokerPlayer& p)
		:GunsLinger(G), PokerPlayer(p) {}
	double Gdraw()const;
	double Cdraw()const;
	void Show()const;
	void Set();
};

#endif

/*
关于protected的测试
*/
class Father
{
	int money = 500;
protected:		//此保护成员函数不能在类外访问  但是可以被派生类的成员函数访问   若此处改成private则下面报错
	int moneyA()
	{
		return money;
	}
};

class Son : public Father
{
public:
	void WantMoney()
	{
		cout << "我想知道Father有多少钱: " <<moneyA()<< endl;

	}

};

#endif

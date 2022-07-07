
#ifndef �����ϰ_H_
#define �����ϰ_H_
#include <valarray>
#include <string>
using std::cin;
using std::cout;
using std::endl;


/*
����  ���Ѿ�
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
	//��ʱ year��bottles������ ��������
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
	std::string label;				//����
	PairArray year_and_bottles;		//��ݺ�ƿ��
	int year;						//�洢�����
public:
	//Ĭ�Ϲ��캯��
	Wine();
	//��Ĭ�Ϲ��캯��
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
˽�м̳���ɵ�һ��
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
	//��ʱ year��bottles������ ��������
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
	//std::string label;				//����
	//PairArray year_and_bottles;		//��ݺ�ƿ��
	int year;						//�洢�����
public:
	//Ĭ�Ϲ��캯��
	Wine();
	//��Ĭ�Ϲ��캯��
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
����
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

//��ʼ������
template<typename T>
inline QueueTp<T>::QueueTp(int n)
	:size(n)
{
	pHead = nullptr;
	items = 0;
}

//��������  �ͷ��ڴ�
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
	items++;		//�ڵ��������
	if (pHead == nullptr)
	{
		//��ͷ�ڵ�
		pHead = pNew;
	}
	else
	{
		//���뵽����β��
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
ջ
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

//��ʼ������
template<typename T>
inline pStack<T>::pStack(int n)
	:size(n)
{
	pHead = nullptr;
	items = 0;
}

//��������  �ͷ��ڴ�
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

//��ջ
template<typename T>
inline bool pStack<T>::push(T& item)
{
	if (isfull())
	{
		return false;
	}
	//�����µĽڵ�
	Node* pNew = new Node;
	pNew->item = item;
	pNew->next = nullptr;
	items++;
	//�������Ϊ��
	if (pHead == nullptr)
	{
		pHead = pNew;
	}
	//�����Ϊ��
	else
	{
		Node* pTemp = pHead;
		while (pTemp->next)
		{
			pTemp= pTemp->next;
		}
		pTemp->next = pNew;	//�ڵ�����
	}
	return true;
}

//��ջ
template<typename T>
inline bool pStack<T>::pop(T& item)
{
	if (isempty())
	{
		return false;
	}
	else
	{
		Node* pTail=pHead;				//�������һ���ڵ�
		while (pTail->next)
		{
			pTail = pTail->next;
		}
		//����ȳ�  ��ɾ��β���ڵ�
		if (pHead==pTail)			//�׽ڵ����β�ڵ� ֻ��һ���ڵ�
		{
			//���ֻ��һ���ڵ�
			item = pHead->item;
			pHead = nullptr;
			items--;
		}
		else
		{
			Node* pPreTail = pHead;
			while (pPreTail->next!=pTail)		//�ҵ���ɾ������ǰһ���ڵ�
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
������
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
	�鱣��������ȡ�����Ա��Ϣ, ʹ����������Լ�ӷ���;
	*/
	virtual void Data()const;		//��ʽ�������Ϣ
	virtual void Get();				//������Ϣ
public:
	Person(const string& fn = "none", const string& ln = "none")
		:fname(fn), lname(ln) {}
	Person(const Person& p)
		:fname(p.fname), lname(p.lname) {}
	virtual ~Person() = 0;
	//��ʾ��Ϣ
	virtual void Show()const = 0;	//���麯��
	//������Ϣ
	virtual void Set() = 0;
};

//�����
class GunsLinger : virtual public Person
{
private:
	int num;	//�̺���
protected:
	void Data()const;
	void Get();			//��дnum��Ա����
public:
	GunsLinger(const string& fn = "none", const string& ln = "none", int number = 0)
		:Person(fn, ln), num(number) {}
	GunsLinger(const Person& p, int number)
		:Person(p), num(number) {}
	double Draw()const;	//����ǹ�ֵİ�ǹʱ��
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
����protected�Ĳ���
*/
class Father
{
	int money = 500;
protected:		//�˱�����Ա�����������������  ���ǿ��Ա�������ĳ�Ա��������   ���˴��ĳ�private�����汨��
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
		cout << "����֪��Father�ж���Ǯ: " <<moneyA()<< endl;

	}

};

#endif


/*
ģ����д��һ���ļ�����
*/

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cstdlib>
using std::endl;
using std::cout;
using std::cin;

/*
ģ��ջ����
*/
#if 0
//ģ��ʵ���� ���廯
template <typename Type>
class Stack
{
private:
	enum { MAX = 10 };
	Type items[MAX];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const Type& item);	//��ջ
	bool pop(Type& item);			//��ջ
};
//Ӧ��ģ�����ض���ģ��ʵ��������һ��ʹ��

template<typename Type>
Stack<Type>::Stack()
{
	top = 0;
}

template <typename Type>
bool Stack<Type>::isempty()
{
	return top == 0;
}

template<typename Type>
inline bool Stack<Type>::isfull()
{
	return top==MAX;
}

template<typename Type>
inline bool Stack<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename Type>
inline bool Stack<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
	{
		return false;
	}
}
#endif


/*
ָ��ջ   �õ�new�ĵط���Ҫ�õ� ���ƹ��캯�� �������� ���ظ�ֵ�����
*/
#if 0
template <typename Type>
class Stack
{
private:
	enum { MAX = 10 };
	int stacksize;		//��¼ջ�����Ԫ�ظ���
	Type* items;		//ָ��ջ
	int top;			//��¼����
public:
	explicit Stack(int ss = MAX);
	Stack(const Stack& st);				//���ƹ��캯��
	~Stack() { delete[]items; }			//��������
	bool isempty() { return top == 0; };
	bool isfull() { return top == stacksize; };
	bool push(const Type& item);		//��ջ
	bool pop(Type& item);				//��ջ
	Stack& operator=(const Stack& st);	//��ֵ�����
};
//Ӧ��ģ�����ض���ģ��ʵ��������һ��ʹ��

//Ĭ�Ϲ��캯��
template<typename Type>
Stack<Type>::Stack(int ss)
	:stacksize(ss),top(0)
{
	items = new Type[stacksize];		//Ϊջ�����ڴ�ռ�
}

//���ƹ��캯��
template<typename Type>
Stack<Type>::Stack(const Stack& st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
	{
		items[i] = st.items[i];
	}
}

template<typename Type>
inline bool Stack<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename Type>
inline bool Stack<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
	{
		return false;
	}
}

template <typename Type>
//ָ���������ͻ���ʹ�������������ʱ����ʹ�������� Stack<Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st)
{
	if (this == &st)
		return *this;
	delete[]items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
	{
		items[i] = st.items[i];
	}
	return *this;
}
#endif



/*
����ģ��ʵ���ͷ����Ͳ���
*/
#if 0
//���Ͳ��� �� ������/���ʽ����
template <class T,int n>	//n��ֵ�޷��޸�
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP() {};
	explicit ArrayTP(const T& v);
	virtual T& operator[](int i);
	virtual T operator[](int i)const;
};

template<class T, int n>
inline ArrayTP<T, n>::ArrayTP(const T& v)
{
	for (int i = 0; i < n; i++)
	{
		ar[i] = v;
	}
}

//�����޸�������±�����
template<class T, int n>
inline T& ArrayTP<T, n>::operator[](int i)
{
	if (i<0 || i>n)
	{
		std::cerr << "��������ĳ�������: " << i << endl;
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

//ֻ��������
template<class T, int n>
inline T ArrayTP<T, n>::operator[](int i) const
{
	if (i<0 || i>n)
	{
		std::cerr << "��������ĳ�������: " << i << endl;
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

#endif 

/*
ʹ�ö�����Ͳ���
*/
#if 0
template <class T1,class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	//��������ʹ�ÿ����޸����ݳ�Ա��ֵ
	//�޸ĵ��� ������
	T1& first();
	T2& second();		

	//��ӡ����������
	T1 first()const { return a; }
	T2 second()const { return b; }

	//��Ĭ�Ϲ��캯��
	Pair(const T1& aval, const T2& bval)
		:a(aval), b(bval) {}
	//Ĭ�Ϲ��캯��
	Pair() {}
};

//�޸� a
template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
	return a;
}

//�޸� b
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}
#endif 


/*
��Աģ��
*/
#if 0
template <typename T>
class Beta
{
private:
	template <typename V>
	class Gold
	{
	private:
		V val;
	public:
		Gold(V v = 0)
			:val(v) {}
		void show()const
		{
			std::cout << val << endl;
		}
		V value()const
		{
			return val;
		}
	};
	Gold<T> q;
	Gold<int> n;
public:
	Beta(T t, int i)
		:q(t), n(i) {}
	// U �ɸ÷���������ʱ�Ĳ���ֵ��ʾȷ�� 
	// T �ɶ����ʵ��������ȷ��
	template <typename U>
	U blab(U u, T t)
	{
		return (n.value() + q.value()) * u / t;
	}
	void show()const
	{
		q.show();
		n.show();
	}

};
#endif 

/*
ģ�����
*/
//ģ������
#if 0
template <template<typename T>class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	bool push(int a, double x)
	{
		//ʵ���������˼���  ��������push��pop���� 
		/*
		Crab�����ʹ���κ���Thing��������ƥ�䣬���Ұ�������push��pop��ģ����
		*/
		return s1.push(a) && s2.push(x);
	}
	bool pop(int& a, double& b)
	{
		return s1.pop(a) && s2.pop(b);
	}
};

#endif

//------------------ģ������Ԫ----------------------
/*
1. ��ģ����Ԫ
*/
#if 0
template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T& i)
		:item(i)
	{
		ct ++;
	}
	~HasFriend()
	{
		ct--;
	}
	friend void counts();
	friend void reports(HasFriend<T>&);
};

template <typename T>
int HasFriend<T>::ct = 0;		//���ۺ������� �����㿪ʼ

void counts()
{
	cout << "int count: " << HasFriend<int>::ct << endl;
	cout << "double count: " << HasFriend<double>::ct << endl;
}

inline void reports(HasFriend<int>& hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

inline void reports(HasFriend<double>& hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}
#endif

//Լ��ģ����Ԫ����
/*
1. ���ඨ���ǰ������ÿ��ģ�庯��
2. �ں������ٴν�ģ������Ϊ��Ԫ
*/

//�����ⲿ������ģ��
#if 0
template <typename T>void counts();
template <typename T>void report(T&);

template <typename TT>
class HasFrinedT
{
private:
	TT item;
	static int ct;
public:
	HasFrinedT(const TT& i)
		:item(i)
	{
		ct ++ ;
	}
	~HasFrinedT()
	{
		ct--;
	}
	//countsû�в��� ����ʹ��ģ������﷨<TT> ��ָ������廯
	friend void counts<TT>();
	//report�в��� ��˸��ݺ����β����ƶϳ�ģ�����Ͳ��� ����<>
	friend void report<>(HasFrinedT<TT>&);
};

template <typename T>
int HasFrinedT<T>::ct = 0;		//���ۺ������� �����㿪ʼ

template <typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFrinedT<T>) << endl;
	cout << "template count: " << HasFrinedT<T>::ct << endl;
}

template<typename T>
inline void report(T& hf)
{
	cout << hf.item << endl;
}
#endif


//��Լ��ģ����Ԫ����

template <typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T& i)
		:item(i) {}
	//�����ڲ�����ģ�� ������Լ��ģ����Ԫ����
	template <typename C, typename D>
	friend void show2(C&, D&);
};

template<typename C, typename D>
inline void show2(C& c, D& d)
{
	cout << c.item <<" "<< d.item << endl;
}
#endif // !STAKC_H_
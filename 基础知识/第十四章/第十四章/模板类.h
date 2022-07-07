
/*
模板类写在一个文件即可
*/

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cstdlib>
using std::endl;
using std::cout;
using std::cin;

/*
模板栈操作
*/
#if 0
//模板实例化 具体化
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
	bool push(const Type& item);	//入栈
	bool pop(Type& item);			//出栈
};
//应将模板与特定的模板实例化放在一起使用

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
指针栈   用到new的地方就要用到 复制构造函数 析构函数 重载赋值运算符
*/
#if 0
template <typename Type>
class Stack
{
private:
	enum { MAX = 10 };
	int stacksize;		//记录栈的最大元素个数
	Type* items;		//指针栈
	int top;			//记录顶部
public:
	explicit Stack(int ss = MAX);
	Stack(const Stack& st);				//复制构造函数
	~Stack() { delete[]items; }			//析构函数
	bool isempty() { return top == 0; };
	bool isfull() { return top == stacksize; };
	bool push(const Type& item);		//入栈
	bool pop(Type& item);				//出栈
	Stack& operator=(const Stack& st);	//赋值运算符
};
//应将模板与特定的模板实例化放在一起使用

//默认构造函数
template<typename Type>
Stack<Type>::Stack(int ss)
	:stacksize(ss),top(0)
{
	items = new Type[stacksize];		//为栈分配内存空间
}

//复制构造函数
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
//指定返回类型或者使用作用域解析符时必须使用完整的 Stack<Type>
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
数组模板实例和非类型参数
*/
#if 0
//类型参数 和 非类型/表达式参数
template <class T,int n>	//n的值无法修改
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

//可以修改数组的下标引用
template<class T, int n>
inline T& ArrayTP<T, n>::operator[](int i)
{
	if (i<0 || i>n)
	{
		std::cerr << "超出数组的长度限制: " << i << endl;
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

//只读的数组
template<class T, int n>
inline T ArrayTP<T, n>::operator[](int i) const
{
	if (i<0 || i>n)
	{
		std::cerr << "超出数组的长度限制: " << i << endl;
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

#endif 

/*
使用多个类型参数
*/
#if 0
template <class T1,class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	//返回引用使得可以修改数据成员的值
	//修改调用 这两个
	T1& first();
	T2& second();		

	//打印调用这两个
	T1 first()const { return a; }
	T2 second()const { return b; }

	//非默认构造函数
	Pair(const T1& aval, const T2& bval)
		:a(aval), b(bval) {}
	//默认构造函数
	Pair() {}
};

//修改 a
template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
	return a;
}

//修改 b
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}
#endif 


/*
成员模板
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
	// U 由该方法被调用时的参数值显示确定 
	// T 由对象的实例化类型确定
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
模板参数
*/
//模板类型
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
		//实际上是做了假设  假设其有push与pop方法 
		/*
		Crab类可以使用任何与Thing类型声明匹配，并且包含方法push和pop的模板类
		*/
		return s1.push(a) && s2.push(x);
	}
	bool pop(int& a, double& b)
	{
		return s1.pop(a) && s2.pop(b);
	}
};

#endif

//------------------模板与友元----------------------
/*
1. 非模板友元
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
int HasFriend<T>::ct = 0;		//无论何种类型 都从零开始

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

//约束模板友元函数
/*
1. 在类定义的前面声明每个模板函数
2. 在函数中再次将模板声明为友元
*/

//在类外部声明的模板
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
	//counts没有参数 必须使用模板参数语法<TT> 来指明其具体化
	friend void counts<TT>();
	//report有参数 因此根据函数形参能推断出模板类型参数 无需<>
	friend void report<>(HasFrinedT<TT>&);
};

template <typename T>
int HasFrinedT<T>::ct = 0;		//无论何种类型 都从零开始

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


//非约束模板友元函数

template <typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T& i)
		:item(i) {}
	//在类内部声明模板 创建非约束模板友元函数
	template <typename C, typename D>
	friend void show2(C&, D&);
};

template<typename C, typename D>
inline void show2(C& c, D& d)
{
	cout << c.item <<" "<< d.item << endl;
}
#endif // !STAKC_H_
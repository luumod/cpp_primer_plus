


#ifndef TV_H_
#define TV_H_

/*
友元类
*/
#if 0
class Tv
{
private:
	int state;		//电视开关
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	/*
	定义整个类作为其友元  使得Remote中的所有函数都可以访问Tv的私有成员
	*/
	friend class Remote;	//Remote成为Tv的一个友元类
	enum {OFF,ON};
	enum {MinVal,MaxVal=20};
	enum {Antrnna,Cable};
	enum {TV,DVD};

	Tv(int s = OFF, int mc = 125)
		:state(s), volume(5), maxchannel(mc), channel(2),
		mode(Cable), input(TV) {}
	void onoff()
	{
		state = (state == ON) ? OFF : ON;
	}
	bool ison()const
	{	//是否处于打开状态
		return state == ON;
	}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode()
	{
		mode = (mode == Antrnna) ? Cable : Antrnna;
	}
	void set_input()
	{
		input = (input == TV) ? DVD : TV;
	}
	void settings()const;		//显示所有数据
};

class Remote
{
private:
	int mode;
public:
	Remote(int m = Tv::TV) :mode(m) {}
	bool volup(Tv& t)
	{
		return t.volup();
	}
	bool voldown(Tv& t)
	{
		return t.voldown();
	}
	void onoff(Tv& t)
	{
		return t.onoff();
	}
	void chanup(Tv& t)
	{
		return t.chanup();
	}
	void chandown(Tv& t)
	{
		return t.chandown();
	}
	void set_chan(Tv& t, int c)
	{
		t.channel = c;
	}
	void set_mode(Tv& t)
	{
		return t.set_mode();
	}
	void set_input(Tv& t)
	{
		return t.set_input();
	}
};

#endif


/*
前向声明 
*/
#if 0
//类声明
class Tv;		//让编译器知道Tv是一个类

/*
注意:  此时只是让编译器知道有个Tv的类  并没有定义Tv类的具体方法
*/


class Remote
{
public:
	enum { OFF, ON };
	enum { MinVal, MaxVal = 20 };
	enum { Antrnna, Cable };
	enum { TV, DVD };
private:
	int mode;
public:
	Remote(int m = Tv::TV) :mode(m) {}
	/*
	在Remote声明中只包含方法声明  将实际的定义放在Tv类之后
	*/
	bool volup(Tv& t);
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_mode(Tv& t);
	void set_input(Tv& t);
	void set_chan(Tv& t, int c);  //需要作为友元的函数
};

//类定义
class Tv
{
private:
	int state;		//电视开关
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	//friend class Remote;	//Remote成为Tv的一个友元类
	/*
	1. 应该先知道Remote的定义 因此应将Remote类的定义放在前面
	2. 但是Remote类中也包含了Tv类的成员函数 因此也要将Tv放在前面

	由此引出---->>>前向声明 
	*/
	//只有这一个函数是Tv的友元 只有他能够访问Tv的私有成员
	friend void Remote::set_chan(Tv& t, int c);

	enum { OFF, ON };
	enum { MinVal, MaxVal = 20 };
	enum { Antrnna, Cable };
	enum { TV, DVD };

	Tv(int s = OFF, int mc = 125)
		:state(s), volume(5), maxchannel(mc), channel(2),
		mode(Cable), input(TV) {}
	void onoff()
	{
		state = (state == ON) ? OFF : ON;
	}
	bool ison()const
	{	//是否处于打开状态
		return state == ON;
	}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode()
	{
		mode = (mode == Antrnna) ? Cable : Antrnna;
	}
	void set_input()
	{
		input = (input == TV) ? DVD : TV;
	}
	void settings()const;		//显示所有数据
};


inline bool Remote::volup(Tv& t)
{
	return t.volup();
}
inline bool Remote::voldown(Tv& t)
{
	return t.voldown();
}
inline void Remote::onoff(Tv& t)
{
	return t.onoff();
}
inline void Remote::chanup(Tv& t)
{
	return t.chanup();
}
inline void Remote::chandown(Tv& t)
{
	return t.chandown();
}
inline void Remote::set_mode(Tv& t)
{
	return t.set_mode();
}
inline void Remote::set_input(Tv& t)
{
	return t.set_input();
}
inline void Remote::set_chan(Tv& t, int c)
{
	t.channel = c;
}   //需要作为友元的函数

#endif


/*
 模板中的类嵌套
*/
#if 1

template <typename T>
class QueueTP
{
private:
	enum { Q_SIZE = 10 };
	/*
	类嵌套 
	*/
	class Node
	{
	public:
		T item;
		Node* next;
		//默认构造函数  自动初始化新的Node节点
		Node(const T& i) :item(i), next(nullptr) {}	
	};

	Node* front;		//指向首节点的指针
	Node* rear;			//指向尾节点的指针
	int items;			//队列现有元素个数
	const int qsize;	//队列最大元素个数
	QueueTP(const QueueTP& q) :qsize(0) {}
	QueueTP& operator=(const QueueTP& q)
	{
		return *this;
	}
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty()const
	{
		return items == 0;
	}
	bool isfull()const
	{
		return items == qsize;
	}
	bool enqueue(const T& item);	//入队
	bool delqueue(T& item);			//出队
};

//构造函数  初始化
template<typename T>
inline QueueTP<T>::QueueTP(int qs)
	:qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

//析构函数  释放节点
template<typename T>
inline QueueTP<T>::~QueueTP()
{
	Node* pDel;					//要删除的节点
	while (front)
	{
		pDel = front;			//保存要删除的节点的地址
		front = front->next;	//链表更新
		delete pDel;			//删除保存的节点
	}
}

//入队
template<typename T>
inline bool QueueTP<T>::enqueue(const T& item)
{
	if (isfull())
	{
		return false;
	}
	Node* pNew = new Node(item);	//创建节点 顺便初始化
	items++;
	if (front == 0)
	{
		//如果没有节点
		front = rear = pNew;
	}
	else
	{
		rear->next = pNew;			//尾部节点和新节点连接 尾插
	}
	rear = pNew;
	return true;
}

//出队
template<typename T>
inline bool QueueTP<T>::delqueue(T& item)
{
	if (isempty())
	{
		return false;
	}
	//队列:   先进先出  后进后出  删除第一个
	item = front->item;	
	items--;
	Node* pDel = front;			//保存要删除的节点的位置
	front = front->next;
	delete pDel;
	if (items == 0)
	{
		front = rear = nullptr;
	}
	return true;
}


#endif
#endif 

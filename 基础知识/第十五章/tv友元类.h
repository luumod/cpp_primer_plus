


#ifndef TV_H_
#define TV_H_

/*
��Ԫ��
*/
#if 0
class Tv
{
private:
	int state;		//���ӿ���
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	/*
	������������Ϊ����Ԫ  ʹ��Remote�е����к��������Է���Tv��˽�г�Ա
	*/
	friend class Remote;	//Remote��ΪTv��һ����Ԫ��
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
	{	//�Ƿ��ڴ�״̬
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
	void settings()const;		//��ʾ��������
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
ǰ������ 
*/
#if 0
//������
class Tv;		//�ñ�����֪��Tv��һ����

/*
ע��:  ��ʱֻ���ñ�����֪���и�Tv����  ��û�ж���Tv��ľ��巽��
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
	��Remote������ֻ������������  ��ʵ�ʵĶ������Tv��֮��
	*/
	bool volup(Tv& t);
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_mode(Tv& t);
	void set_input(Tv& t);
	void set_chan(Tv& t, int c);  //��Ҫ��Ϊ��Ԫ�ĺ���
};

//�ඨ��
class Tv
{
private:
	int state;		//���ӿ���
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	//friend class Remote;	//Remote��ΪTv��һ����Ԫ��
	/*
	1. Ӧ����֪��Remote�Ķ��� ���Ӧ��Remote��Ķ������ǰ��
	2. ����Remote����Ҳ������Tv��ĳ�Ա���� ���ҲҪ��Tv����ǰ��

	�ɴ�����---->>>ǰ������ 
	*/
	//ֻ����һ��������Tv����Ԫ ֻ�����ܹ�����Tv��˽�г�Ա
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
	{	//�Ƿ��ڴ�״̬
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
	void settings()const;		//��ʾ��������
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
}   //��Ҫ��Ϊ��Ԫ�ĺ���

#endif


/*
 ģ���е���Ƕ��
*/
#if 1

template <typename T>
class QueueTP
{
private:
	enum { Q_SIZE = 10 };
	/*
	��Ƕ�� 
	*/
	class Node
	{
	public:
		T item;
		Node* next;
		//Ĭ�Ϲ��캯��  �Զ���ʼ���µ�Node�ڵ�
		Node(const T& i) :item(i), next(nullptr) {}	
	};

	Node* front;		//ָ���׽ڵ��ָ��
	Node* rear;			//ָ��β�ڵ��ָ��
	int items;			//��������Ԫ�ظ���
	const int qsize;	//�������Ԫ�ظ���
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
	bool enqueue(const T& item);	//���
	bool delqueue(T& item);			//����
};

//���캯��  ��ʼ��
template<typename T>
inline QueueTP<T>::QueueTP(int qs)
	:qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

//��������  �ͷŽڵ�
template<typename T>
inline QueueTP<T>::~QueueTP()
{
	Node* pDel;					//Ҫɾ���Ľڵ�
	while (front)
	{
		pDel = front;			//����Ҫɾ���Ľڵ�ĵ�ַ
		front = front->next;	//�������
		delete pDel;			//ɾ������Ľڵ�
	}
}

//���
template<typename T>
inline bool QueueTP<T>::enqueue(const T& item)
{
	if (isfull())
	{
		return false;
	}
	Node* pNew = new Node(item);	//�����ڵ� ˳���ʼ��
	items++;
	if (front == 0)
	{
		//���û�нڵ�
		front = rear = pNew;
	}
	else
	{
		rear->next = pNew;			//β���ڵ���½ڵ����� β��
	}
	rear = pNew;
	return true;
}

//����
template<typename T>
inline bool QueueTP<T>::delqueue(T& item)
{
	if (isempty())
	{
		return false;
	}
	//����:   �Ƚ��ȳ�  ������  ɾ����һ��
	item = front->item;	
	items--;
	Node* pDel = front;			//����Ҫɾ���Ľڵ��λ��
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

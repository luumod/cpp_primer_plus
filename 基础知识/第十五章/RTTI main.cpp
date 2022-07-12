
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
	���н׶�����ʶ��

	dynameic_cast
	typeid
	type_info
*/

//dynamic_cast  ǿ������ת��

#if 0

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) :hold(h) {}
	/*
	������һ���麯�� ������Ҳ�����¶����˸��麯��
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
	һ���µ��麯��
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
		//����ָ�����ָ���������ָ�������
		pG = Getone();	//�������һ������
		pG->Speak();	//�麯�� �����Զ����ö�Ӧ�汾��Speak����
		/*
		����ת���ɹ�  pSΪ����; ʧ�� ��pSΪ��

		��������: bad_cast
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
				ΪʲôҪת��ΪSuperb ?
			ת��ΪSuperb ����ʹ����������Ҳ���Ե�����Superb���ж�����麯��
			����ָ�����ָ���������ָ��  ���Ҳ���Ե���������ĺ���
			*/
			pS->Say();	
		}
		/*if (pM = dynamic_cast<Magnifiaent*>(pG))
		{
			pM->Say();		//ֻ�ܵ���Magnifient���Say  ���ܵ�����һ�����麯��Say
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



//typeid����� �� type_info ��

/*
typeid �����ʹ���ܹ�ȷ�����������Ƿ�Ϊͬ�����ͣ��������ֲ���:
	����
	���Ϊ����ı��ʽ
����һ��type_info��������� 
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
#if 1	//dynamic_cast����
	for (int i = 0; i < 5; i++)
	{
		//����ָ�����ָ���������ָ�������
		pG = Getone();	//�������һ������
		cout << "Now process type " << typeid(*pG).name() << endl;
		pG->Speak();	//�麯�� �����Զ����ö�Ӧ�汾��Speak����
		/*
		��� pG ָ�����һ��Magnificent�Ķ��� �򷵻�true
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
#else	//typeid ����
	for (int i = 0; i < 5; i++)
	{
		//����ָ�����ָ���������ָ�������
		pG = Getone();	//�������һ������
		/*
		��� pG ָ�����һ��Magnificent�Ķ��� �򷵻�true
		*/
		if ((typeid(Magnifiaent) == typeid(*pG)))
		{
			//Magnifiaent����
			pM = (Magnifiaent*)pG;
			pM->Speak();
			pM->Say();
		}
		else if (typeid(Superb)==typeid(*pG))
		{
			//Superb����
			pS = (Superb*)pG;
			pS->Speak();
			pS->Say();
		}
		else
		{
			//��������
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
����ת�������:
	dynamic_cast
	const_cast;
	static_cast
	reinterpret_cast
*/

//dynamic_cast: ʹ���ܹ������νṹ�н�������ת��

//const_cast:	�ı�ֵΪconst����volatile�ı���

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
	//����һ���µ�int* ָ��
	//��pcָ��ɾ��const��int* ��pt ����൱��pt����˿����޸ĵ�ֵ
	/*
	ֻ�������޸Ĳ���const��ֵ ��ֵ�������const ���޷�ʵ��
	*/
	pc = const_cast<int*>(pt);
	*pc += n;
}

//static_cast ת��

//reinterpret_cast 
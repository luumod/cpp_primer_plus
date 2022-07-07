#include <iostream>
#include "练习题.h"

/*
第一题  第二题
*/
#if 0
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("古具春", YRS, y, b);
	more.Show();
	cout << "总瓶数 " << more.Label();
	cout << ": " << more.sum() << endl;
	cout << "Bye\n";

	return 0;
}


#endif


/*
第三题
*/
#if 0
const int SIZE = 5;
int main()
{
	//QueueTp<int> one[SIZE];
	//int item;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	one->push(i);
	//}
	////出队
	//for (int i = 0; i < SIZE; i++)
	//{
	//	one->pop(item);
	//	cout << item << ", ";
	//}

	/*
	队列演示
	*/

	int ct;
	Worker* temp;
	pStack<Worker*> lolas(SIZE);

	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the menu order:" << endl;
		cout << "a: add a worker to queue." << endl;
		cout << "d: delete a worker from queue." << endl;
		cout << "q: quit." << endl;
		cin >> choice;
		while (NULL == strchr("adq", choice))
		{
			cout << "Please enter a, d or q: ";
			cin >> choice;
		}
		if ('q' == choice)
		{
			break;
		}
		switch (choice)
		{
		case 'a':
		{
			temp = new Worker;
			cin.get();
			if (lolas.isfull()) //若是队列已满则打印信息并释放new分配的内存;
			{
				cout << "Queue is full!" << endl;
				delete temp;
			}
			else
			{
				temp->Set();
				lolas.push(temp);   //入队
			}
			break;
		}
		case 'd':
		{
			if (lolas.isempty())
			{
				cout << "Queue is empty!" << endl;
			}
			else
			{
				lolas.pop(temp);    //出队
				temp->Show();
			}
			break;
		}
		}
	}
	ct = lolas.queuecount();        //显式队列的元素个数
	cout << "\nHere is " << ct << " worker(s) in queue:" << endl;
	for (int i = 0; i < ct; i++)
	{
		lolas.pop(temp);            //依次出队
		temp->Show();   
	}
	cout << "Done.\n";

	return 0;
}

#endif 


/*
链式栈
*/
#if 0
const int SIZE = 10;
int main()
{
	pStack<int> rt;
	int item;
	for (int i = 0; i < SIZE; i++)
	{
		rt.push(i);
	}
	cout << "出栈: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		rt.pop(item);
		rt.show();
	}

	return 0;
}
#endif 

#if 0
const int SIZE = 5;

int main()
{

	int i, ct;
	Person* people[SIZE];

	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the person category:" << endl;
		cout << "g: gunslinger" << endl;
		cout << "p: pokerplayer" << endl;
		cout << "b: baddude" << endl;
		cout << "q: quit" << endl;
		cin >> choice;
		while (NULL == strchr("bgpq", choice))
		{
			cout << "Please enter b, g, p or q: ";
			cin >> choice;
		}
		if ('q' == choice)
		{
			break;
		}
		switch (choice)
		{
		case 'b':
		{
			people[ct] = new BadDude;
			break;
		}
		case 'g':
		{
			people[ct] = new GunsLinger;
			break;
		}
		case 'p':
		{
			people[ct] = new PokerPlayer;
			break;
		}
		}
		cin.get();
		people[ct]->Set();
	}
	cout << "\nHere is your message for some people:" << endl;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		people[i]->Show();
	}
	for (i = 0; i < ct; i++)
	{
		delete people[i];
	}
	cout << "Bye.\n";

	return 0;
}


#endif 

//测试protected
int main()
{
	Son me;
	me.WantMoney();

	return 0;
}
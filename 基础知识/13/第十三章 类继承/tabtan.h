//
//
//
//#ifndef TANTEN_H_
//#define TANTEN_H_
//#include <string>
//using std::string;
//
//class TablenTennusPlay
//{
//private:
//	string firstname;
//	string lastname;
//	int hasTable;
//public:
//	TablenTennusPlay(const string& fn = "none", const string& in = "none", bool ht = false);
//	void Name()const;
//	int HasTable()const
//	{
//		return hasTable;
//	}
//	void ResetTable(int v)
//	{
//		hasTable = v;
//	}
//};
//
//
////�̳�
///*
//���������洢�˻�������ݳ�Ա
//������������ʹ�û���ĳ�Ա
//*/
///*
//��������Ҫ���Լ��Ĺ��캯��
//�����������Ӷ�������ݳ�Ա�ͳ�Ա����
//*/
//class RatedPlay : public TablenTennusPlay
//{
//private:
//	unsigned int rating;		//���һ����Ա
//public:
//	//�����๹�캯������ʹ�û��๹�캯��
//	RatedPlay(unsigned int r = 0, const string& fn = "none",
//		const string& ln = "none", bool ht = false);
//	RatedPlay(unsigned int r, const TablenTennusPlay& tp);
//	unsigned int Rating()const
//	{ 	
//		return rating; 
//	}
//	void ResetRating(unsigned int r) 
//	{
//		rating = r;
//	}/*
//	 ��ʽ���ƹ��캯������ʽ��ֵ��������Խ���������ʼ��Ϊ���������
//	 ���߽���������󸳸��������
//	 */
//};
//
//
//
///*
//����
//*/
//
////�������
//class Brass
//{
//private:
//	std::string fullname;		//�˻�����
//	long acctNum;				//�˻�
//	double balance;				//���
//public:
//	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
//	void Deposit(double amt);	//���
//	/*
//	virtual �鷽�� ���������������Ϊ���в�ͬ
//	*/
//	virtual void WithDraw(double amt);	//ȡ��
//	virtual void ViewAcct()const;		//�鿴�˻�
//	double Balance()const;
//	/*
//	����������
//	*/
//	virtual ~Brass(){}
//};
//
////�̳�
//class BrassPlus :public Brass
//{
//private:
//	//������˽�г�Ա
//	double maxLoan;		//���������
//	double rate;		//�������
//	double owesBank;	//����˻�
//public:
//	//�����Ĺ��г�Ա����
//	BrassPlus(const std::string& s = "NullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
//	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
//	virtual void WithDraw(double amt);	//ȡ��
//	virtual void ViewAcct()const;		//�鿴�˻�
//	void ResetMax(double m)
//	{
//		//���������������
//		maxLoan = m;
//	}
//	void ResetRste(double r)
//	{
//		//��������
//		rate = r;
//	}
//	void ResetOwes()
//	{
//		//�����˻�
//		owesBank = 0;
//	}
//};
//
//
//
//
//#endif // TANTEN_H_

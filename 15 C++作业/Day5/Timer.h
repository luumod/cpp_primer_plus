#pragma once
#include "common.h"

/*
��ʱ��
*/
class Timer
{
private:
	int id;		//��ʱid
	int dis;	//ʱ����

public:
	Timer(int dis, int id) :id(id), dis(dis) {}
	bool timer();
};
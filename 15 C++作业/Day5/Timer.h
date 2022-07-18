#pragma once
#include "common.h"

/*
定时器
*/
class Timer
{
private:
	int id;		//定时id
	int dis;	//时间间隔

public:
	Timer(int dis, int id) :id(id), dis(dis) {}
	bool timer();
};
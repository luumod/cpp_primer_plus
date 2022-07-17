

#include <graphics.h>

//点类
class Point
{
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0);
	~Point();
	//返回点的坐标
	int ReturnPosX()const;
	int ReturnPosY()const;
};


#include <graphics.h>

//����
class Point
{
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0);
	~Point();
	//���ص������
	int ReturnPosX()const;
	int ReturnPosY()const;
};
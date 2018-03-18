#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {}
	
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
	}
	
	friend Point operator+(const Point &pos1, const Point &pos2);
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
	
	Point& operator+=(const Point &pos2)
	{
		xpos += pos2.xpos;
		ypos += pos2.ypos;
		return *this;
	}
	
	Point& operator-=(const Point &pos2)
	{
		xpos -= pos2.xpos;
		ypos -= pos2.ypos;
		return *this;
	}
};

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos+pos2.ypos);
	return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos-pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
	if(pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
	if(pos1 == pos2)
		return false;
	else
		return true;
}


int main(void)
{
	Point pos1(10, 20);
	Point pos2(3, 4);
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	
	pos1 -= pos2;
	
	pos1.ShowPosition();
	
	pos1 += pos1;
	
	pos1.ShowPosition();
	
	cout<<(pos1==pos2)<<endl;
	cout<<(pos1!=pos2)<<endl;
	return 0;
}

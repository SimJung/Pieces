#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y = 0) : xpos(x), ypos(y)
	{ }
	
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
	}	
	
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
	friend istream& operator>>(istream&, Point*&);
};

typedef Point * POINT_PTR;

ostream& operator<< (ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}

istream& operator>> (istream& is, Point& pos)
{
	is>>pos.xpos>>pos.ypos;
	return is;
}

istream& operator>> (istream& is, POINT_PTR& pos)
{
	pos = new Point;
	is>>pos->xpos>>pos->ypos;
	return is;
}

class BoundCheckPointArray
{
private:
	POINT_PTR * arr;
	int arrlen;
	
	BoundCheckPointArray(const BoundCheckPointArray& arr) {	}
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }

public:
	BoundCheckPointArray(int len) :arrlen(len)
	{
		arr = new POINT_PTR[len];
	}
	
	POINT_PTR& operator[] (int idx)
	{
		if(idx < 0 || idx >= arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}
	
	POINT_PTR& operator[] (int idx) const
	{
		if(idx < 0 || idx >= arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}
	
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointArray() { delete []arr; }
	
};

int main(void)
{
	BoundCheckPointArray arr(3);
	
	for(int i=0; i<arr.GetArrLen(); i++)
		cin>>arr[i];
	
	for(int i=0; i<arr.GetArrLen(); i++)
		cout<<*(arr[i]);
		
	for(int i=0; i<arr.GetArrLen(); i++)
		delete arr[i];
	
	return 0;
}


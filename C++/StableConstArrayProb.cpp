#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);	
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
}

class BoundCheckIntArray
{
private:
	int * arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator= (const BoundCheckIntArray& arr) { }
	
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int [len];
	}	
	
	int& operator [] (int idx)
	{
		if(idx < 0 || idx >= arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return arr[idx];
	}
	
	int operator [] (int idx) const
	{
		if(idx < 0 || idx >= arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return arr[idx];
	}
	int GetArrLen() const {return arrlen;}
	~BoundCheckIntArray() {delete []arr;}
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	for(int idx=0; idx<len; idx++)
		cout<<ref[idx]<<endl;
}

int main(void)
{
	BoundCheckIntArray arr(5);
	for(int i=0; i<6; i++)
		arr[i] = (i+1)*11;
		
	ShowAllData(arr);
	
	for(int i=0; i<6; i++)
		cout<<arr[i]<<endl;
	return 0;
}

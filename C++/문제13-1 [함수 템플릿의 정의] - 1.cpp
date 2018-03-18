#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) { }
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
	}
}; 

template <class T>
void SwapData(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
} 

int main(void)
{
	Point p1(6, 3);
	Point p2(7, 9);
	cout<<"Before SwapData"<<endl;
	p1.ShowPosition();
	p2.ShowPosition();
	
	SwapData(p1, p2);
	
	cout<<"After SwapData"<<endl;
	p1.ShowPosition();
	p2.ShowPosition();
}

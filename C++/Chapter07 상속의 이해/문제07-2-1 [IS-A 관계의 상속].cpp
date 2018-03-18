#include <iostream>

using namespace std;

class Rectangle
{
private:
	int width;
	int height;
	
public:
	Rectangle(int x, int y) : width(x), height(y) {}
	
	void ShowAreaInfo(void)
	{
		cout<<"¸éÀû : "<<width * height<<endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int x) : Rectangle(x, x) {}
};

int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();	
	return 0;
}

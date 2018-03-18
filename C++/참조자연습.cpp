#include <iostream>
using namespace std;

int& getnum()
{
	int a = 6;
	return a;
}

int main(void)
{
	int num = getnum();
	cout<<num<<endl;
	return 0;
}

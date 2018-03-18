#include <iostream>

using namespace std;

void plusone(int &ref)
{
	ref++;
}

void upsideone(int &ref)
{
	ref *= -1;
}

int main(void)
{
	int a = 7;
	cout<< a << endl;
	plusone(a);
	cout<<a<<endl;
	upsideone(a);
	cout<<a<<endl;
	return 0;
}

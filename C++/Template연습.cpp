#include <iostream>
using namespace std;

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

template <>
int Add(int a, int b)
{
	return a*b;
} 

int main(void)
{
	cout<<Add(3, 6)<<endl; 
	cout<<Add(3.1455555, 6.56)<<endl;
	cout<<Add(-65, -55)<<endl;
	cout<<Add('A', '3')<<endl;
	return 0;
}

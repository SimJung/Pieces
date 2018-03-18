#include <iostream>

using namespace std;

void Counter(void)
{
	static int cnt;              // static 변수는 초기화하지 않으면 0으로 초기화 된다. 
	cnt++;
	cout<<"Current cnt : "<<cnt<<endl;
}

int main(void)
{
	for(int i=0; i<10; i++)
	{
		Counter();
	}
	return 0;
}

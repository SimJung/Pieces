#include <iostream>

using namespace std;

void Counter(void)
{
	static int cnt;              // static ������ �ʱ�ȭ���� ������ 0���� �ʱ�ȭ �ȴ�. 
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

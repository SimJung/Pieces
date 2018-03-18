#include <iostream>

using namespace std;

int arg[101][1000];

int get_num(int a)
{
	if(arg[a])
		return arg[a];
	
	else
		arg[a] = get_num(a-1) + get_num(a-2);
		return arg[a];
}

int main(void)
{
	int num;
	arg[0] = 0;
	arg[1] = 1;
	arg[2] = 2;
	
	
	while(1)
	{
		cin>>num;
		cout<<get_num(num)%1000000007<<endl;
	}
	
	return 0;
}

#include <iostream>
using namespace std;

int main(void)
{
	int sum = 0, num, min = 100;
	for(int i=0; i<7; i++)
	{
		cin>>num;
		if(num % 2)
		{
			if(min > num)
			min = num;
			sum += num;
		} 
	}
	if(sum)
	{
		cout<<sum<<endl;
		cout<<min<<endl;
	}else
		cout<<-1<<endl;
	
	return 0;
}

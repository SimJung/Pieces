#include <iostream>
#include <cmath>
using namespace std;

int length(int num)
{
	int len = 1;
	while(num /=10)
		len++;
		
	return len;
}

int bigger(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main(void)
{
	int num1, num2, sum;
	cin>>num1>>num2;
	
	while(num1 || num2)
	{
		int len, carry = 0, chk = 0;
		
		len = bigger(length(num1), length(num2));
	
		sum = num1 + num2;
		
		for(int i=0; i<len; i++)
		{
			int n1 = (num1 / (int)(pow(10.0, i))) % 10;
			int n2 = (num2 / (int)(pow(10.0, i))) % 10;
			int n3 = (sum / (int)(pow(10.0, i))) % 10;
			
			if(chk)
			{
				n1++;
				chk--;
			}
			
			if(n3 != n1 + n2)
			{
				carry++;
				chk = 1;
			}
				
		}
		
		if(carry == 1)
			cout<<carry<<" carry operation."<<endl;
		else if(carry)
			cout<<carry<<" carry operations."<<endl;
		else
			cout<<"no carry operations."<<endl;
			
		cin>>num1>>num2;
	}
	
	
	
	return 0;
}

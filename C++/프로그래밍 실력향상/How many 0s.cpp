#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string itoa(int a)
{
	string b = "";
	int len = 1, num = a;
	while(num /= 10)
		len++;
	for(int i=0; i<len; i++)
	{
		b.push_back((a%(int)(pow(10.0, len - i)) / pow(10.0, len - i - 1) + 48));
	}
	return b;
}


int main(void)
{
	while(1)
	{
		int num, num2;
		cin>>num>>num2;
		string str;
		int count = 0;
		for(int i=num; i<=num2; i++)
		{
			str = itoa(i);
			for(int j=0; j<str.length(); j++)
			{
				if(str.at(j) == '0')
				{
					count++;
				}
			}
		}
	cout<<count<<endl;
	}
	
	return 0;
} 

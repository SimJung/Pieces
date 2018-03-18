#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int getlen(int num)
{
	int len = 1;
	while(num /= 10)
		len++;
	return len;
}

int main(void)
{
	int num = 1, str;
	
	int arr[10000];
	
	for(int i=0; i<10000; i++)
	{
		cout<<i<<endl;
		int len = getlen(num), chk = 1;
		int nn = (num / (int)pow(10.0, len - 1)) % 10;
		for(int j=0; j<len; j++)
		{
			int nown = (num / (int)pow(10.0, len - j - 1)) % 10;
			if(nown != nn)
			{
				chk = 0;
				break;
			}
		}
		if(chk)
		{
			arr[i] = ++num;
			num++;
		}
		else
		{
			arr[i] = num;
			num++;
		}
	}
	
	while(cin>>str && str)
	{
		cout<<arr[str]<<endl;
	}
	return 0;
}

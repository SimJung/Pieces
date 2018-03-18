#include <iostream>
#include <cstdio>
#include <algorithm>
#define long long LL
using namespace std;

int bigger(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int algo3n(int num)
{
	int val = 1;
	if(num == 0)
		return 0;
	while(num != 1)
	{
		if(num % 2)
		{
			num = num*3 + 1;
			val++;
		}
		else
		{
			num/=2;
			val++;	
		}
	}
	return val;
}

int main(void)
{
	int a, b;
	while(scanf ("%d %d", &a, &b) != EOF)
	{
		int max = 0, ta = a, tb = b;
		
		if(a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		for(int i=a; i<=b; i++)
		{
			max = bigger(max, algo3n(i));
		}
		cout<<ta<<' '<<tb<<' '<<max<<endl;
	}
	
	
	return 0;
}



#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void rSt(string &a)
{
	string b = "";
	
	for(int i=a.length() - 1; i>=0; i--)
	{
		b.push_back(a.at(i));
	}
	
	a = b;
}

int atoi(string a)
{
	int num = 0;
	for(int i=0; i<a.length(); i++)
	{
		num += (int)(a.at(i) - 48) * pow(10.0, a.length() - i - 1);
	}
	
	return num;
}

int main(void)
{
	
	int tc;
	cin>>tc;
	
	for(int i=0; i<tc; i++)
	{
		string a, b, c;
		cin>>a>>b;
		
		rSt(a);
		rSt(b);
		
		int num1, num2, num3, num4, len = 1, chkzero = 1;
		
		num1 = atoi(a);
		num2 = atoi(b);
		
		num3 = num1+num2;
		
		num4 = num3;
		
		while(num4/=10)
			len++;
		
			
		for(int j=1; j<=len; j++)
		{
			if(num3 == 0)
			{
				cout<<0;
				break;
			}
			
			int aa = (num3 % (int)(pow(10.0, j))) / (int)(pow(10.0, j-1));
			if(aa && chkzero)
			{
				chkzero = 0;
				cout<<aa;
			}else if(aa)
			{
				cout<<aa;
			}else if(!aa && !chkzero)
			{
				cout<<aa;
			}
		}
		cout<<endl;
	}
	return 0;
}

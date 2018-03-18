#include <iostream>
#include <string>

using namespace std;

int strcmp(string a, string b)
{
	if(a.length() > b.length())
		return 1;
		
	else if(a.length() == b.length())
	{
		for(int i=0; i<a.length(); i++)
		{
			cout<<"i : "<<i<<endl; 
			if(a[i] > b[i])
			{
				cout<<"a["<<i<<"] : "<<a[i]<<endl;
				cout<<"b["<<i<<"] : "<<b[i]<<endl;
				return 1;
			}else if(a[i] < b[i])
			{
				return 0;
			}
				
		}
	}
	return 0;
}

int main(void)
{
	string a,b;
	a = "52";
	b = "61";
	
	cout<<strcmp(a, b)<<endl;
	return 0;
}

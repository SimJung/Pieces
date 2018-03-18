#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int testcase;
	cin>>testcase;
	
	for(int tc = 0; tc<testcase; tc++)
	{
		string a;
		cin>>a;
		int len = a.length();
		
		string *arr = new string [len/2];
		
		for(int i=0; i<len/2; i++)
		{
			arr[i] = "";
		}
		
		for(int i=0; i<len; i+=2)
		{
			arr[i/2].push_back(a.at(i));
			arr[i/2].push_back(a.at(i+1));
		}
		
		int chk = 0;
		
		for(int i=0; i<len/2; i++)
		{
			for(int j=i+1; j<len/2; j++)
			{
				if(arr[i].at(0) > arr[j].at(0))
					chk = 1;
				else if(arr[i].at(0) == arr[j].at(0))
				{
					if(arr[i].at(1) > arr[j].at(1))
						chk = 1;
				}
				if(chk)
				{
					string swap = arr[i];
					arr[i] = arr[j];
					arr[j] = swap;
				}
				chk = 0;
			}
		}
		
		for(int i=0; i<len/2; i++)
		{
			cout<<arr[i];
		}
		cout<<endl;
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int arr[100][100] = {0, };
	int testcase;
	cin>>testcase;
	
	for(int tc = 0; tc<testcase; tc++)
	{
		string indi;
		int x, y, l;
		cin>>indi>>x>>y>>l;
		
		if(indi == "BLACK")
		{
			for(int i=x-1; i<x+l-1; i++)
			{
				for(int j=y-1; j<y+l-1; j++)
					arr[i][j] = 1;
			}
		}else if(indi == "WHITE")
		{
			for(int i=x-1; i<x+l-1; i++)
			{
				for(int j=y-1; j<y+l-1; j++)
					arr[i][j] = 0;
			}
		}else if(indi == "TEST")
		{
			int count = 0;
			for(int i=x-1; i<x+l-1; i++)
			{
				for(int j=y-1; j<y+l-1; j++)
				{
					if(arr[i][j])
						count++;	
				}
			}
			cout<<count<<endl;
		}
	}
	return 0;
}

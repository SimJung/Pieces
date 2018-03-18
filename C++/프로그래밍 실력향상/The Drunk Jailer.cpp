#include <iostream>

using namespace std;

int main(void)
{
	int tc;
	cin>>tc;
	
	for(int i=0; i<tc; i++)
	{
		int n, sum = 0;
		cin>>n;
		
		int * arr = new int [n];
		for(int j=0; j<n; j++)
			arr[j] = 1;
			
		for(int j=2; j<=n; j++)
		{
			for(int k=1; k<=n; k++)
			{
				if(k*j > n)
				{
					break;
				}
				if(arr[k*j - 1])
					arr[k*j - 1] = 0;
				else
					arr[k*j - 1] = 1;				
			}
		} 
		for(int j=0; j<n; j++)
		{
			if(arr[j])
				sum++;
		}
		
		cout<<sum<<endl;
	}

	return 0;
}

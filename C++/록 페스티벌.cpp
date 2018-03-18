#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
	int testcase;
	cin>>testcase;
	
	for(int tc=0; tc<testcase; tc++)
	{
		int days, teams;
		double min = 0;
		scanf("%d %d", &days, &teams);
		
		int * arr = new int [days];
		for(int i=0; i<days; i++)
		{
			scanf("%d", &arr[i]);
			min += arr[i];
		}
			
		for(int i=0; i<days - teams; i++)
		{			
			for(int j=teams; j<days; j++)
			{
				double sum = 0;
				cout<<"i가 "<<i<<"이고 j가 "<<j<<"일 때"<<endl; 
				
				int count;
				
				for(count = i; count<j+i; count++)
				{
					if(count >= days)
						break;
					else
						sum += arr[count];
				}
				
				sum /= count;
				
				cout<<"sum 은 : "<<sum<<endl;
				
				if(min > sum)
				{
					min = sum;
					cout<<"i : "<<i<<endl;
					cout<<"j : "<<j<<endl;
					cout<<"sum : "<<sum<<endl;
				}
					
			}
		}
		
		printf("%lf\n", min);
	}
	return 0;
}

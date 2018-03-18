#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int num;
	
	while(cin>>num && num != -1)
	{
		long long int **arr = new long long int * [num];
		long long int **val = new long long int * [num];
		
		for(int i=0; i<num; i++)
		{
			arr[i] = new long long int [num];
			val[i] = new long long int [num];
		}
		
		for(int i=0; i<num; i++)
		{
			long long int row;
			cin>>row;
			for(int j=0; j<num; j++)
			{
				int nn = (int)(row / pow(10.0, num - j - 1)) % 10;
				arr[i][j] = nn;
				val[i][j] = 0;
			}
		}
		
		val[0][0] = 1;
		
		for(int i=0; i<num; i++)
		{
			for(int j=0; j<num; j++)
			{
				if(val[i][j] && arr[i][j])
				{
					if(i+arr[i][j] < num)
						val[i+arr[i][j]][j] += val[i][j];
					
					if(j+arr[i][j] < num)
						val[i][j+arr[i][j]] += val[i][j];
				}
			}
		}
		
		cout<<val[num - 1][num - 1]<<endl;
	}
	return 0;
}

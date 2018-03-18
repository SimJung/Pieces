#include <iostream>

using namespace std;

int main(void)
{
	int testCase;
	cin>>testCase;
	
	for(int tc=0; tc<testCase; tc++)
	{
		int num;
		cin>>num;
		
		int **arr = new int * [num];
		int **val = new int * [num];
		
		for(int i=0; i<num; i++)
		{
			arr[i] = new int [num];
			val[i] = new int [num];
		}
		
		for(int i=0; i<num; i++)
		{
			for(int j=0; j<num; j++)
			{
				cin>>arr[i][j];
				val[i][j] = 0;
			}
		}
		
		val[0][0] = 1;
		
		for(int i=0; i<num; i++)
		{
			for(int j=0; j<num; j++)
			{
				if(val[i][j])
				{
					if(i+arr[i][j] < num)
						val[i+arr[i][j]][j] = 1;
					
					if(j+arr[i][j] < num)
						val[i][j+arr[i][j]] = 1;
				}
			}
		}
		
		if(val[num - 1][num - 1])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}
	
	return 0;
}

#include <iostream>

using namespace std;

int biggerOne(int a, int b, int c)
{
	if(a + b >= a + c)
		return a + b;
	else
		return a + c;
}

int main(void)
{
	int num;
	cin>>num;
	
	int **arr = new int *[num];
	int **arr2 = new int *[num];
	
	for(int i=0; i<num; i++)
	{
		arr[i] = new int[num];
		arr2[i] = new int[num];
	}
	
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<=i; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	arr2[0][0] = arr[0][0];
	
	for(int i=1; i<num; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(j == 0)
				arr2[i][j] = arr[i][j] + arr2[i-1][j];	
			else if(j == i)
				arr2[i][j] = arr[i][j] + arr2[i-1][j-1];
			else
				arr2[i][j] = biggerOne(arr[i][j], arr2[i-1][j-1], arr2[i-1][j]);
		}
	}
	
	int maxOne = 0;
	for(int i=0; i<num; i++)
	{
		if(maxOne <= arr2[num-1][i])
			maxOne = arr2[num-1][i];
	}
	
	cout<<maxOne<<endl;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int testcase;
	scanf("%d",&testcase);
	
	for(int i=0; i<testcase; i++)
	{
		int num1, num2;
		
		
		scanf("%d",&num1);
		
		int *arr1 = new int[num1];
		
		for(int j=0; j<num1; j++)
		{
			scanf("%d", &arr1[j]);
		}
		
		
		scanf("%d",&num2);
		
		int *arr2 = new int[num2];
		
		for(int j=0; j<num2; j++)
		{
			scanf("%d", &arr2[j]);
		}
		
		
		sort(arr1, arr1 + num1);
		

		for(int j=0; j<num2; j++)
		{
			if(binary_search(arr1, arr1 + num1, arr2[j]))
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
				
				
		}
	}
	
	return 0;
}

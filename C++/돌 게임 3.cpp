#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin>>num;
	
	int arr[1000] = {0, };
	
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 1;
	arr[3] = 1;
	
	for(int i=4; i<1000; i++)
	{
		int k = i;
		while(k >= 4)
		{
			if(arr[k-1] == 2 || arr[k-3] == 2 || arr[k-4] == 2)
			{
				arr[i] = 2;
				break;
			}
				
			else if(arr[k-1] == 1 || arr[k-3] == 1 || arr[k-4] == 1)
			{
				arr[i] = 1;
				break;
			}
			k--;
		}
	}
	
	if(arr[num-1] == 1)
		cout<<"SK"<<endl;
	else if(arr[num-1] == 2)
		cout<<"CY"<<endl;
	return 0;
}

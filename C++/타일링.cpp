#include <iostream>

using namespace std;

int arr[101];

int get_tile(int n)
{
	if(arr[n])
		return arr[n]%1000000007;
	else	
	{
		arr[n] = get_tile(n-1)%1000000007 + get_tile(n-2)%1000000007;
		return arr[n]%1000000007;
	}
}

int main(void)
{
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	
	int tc;
	cin>>tc;
	for(int i=0; i<tc; i++)
	{
		int num;
		cin>>num;
		
		cout<<get_tile(num)<<endl;
	}
	
	return 0;
}

#include <iostream>
using namespace std;

int main(void)
{
	int testcase;
	cin>>testcase;
	
	for(int tc = 1; tc<=testcase; tc++)
	{
		int n;
		long long int arr[1000] = {0, }, sum = 0;
		scanf("%d", &n);
		
		arr[0] = 1;
		for(int i=1; i<1000; i++)
			arr[i] = arr[i-1]+i+1;
			
		for(int i=1; i<=n; i++)
			sum += arr[i] * i;
			
		printf("%d %d %lld\n", tc, n, sum);
	}
	return 0;
}


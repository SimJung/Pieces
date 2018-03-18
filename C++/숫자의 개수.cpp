#include <iostream>
#include <cmath>
using namespace std;

int getlen(int num)
{
	int len = 1;
	while(num /= 10)
		len++;
	return len;
}

int main(void)
{
	int a, b, c, multi, arr[10] = {0, }, len;
	cin>>a>>b>>c;
	
	multi = a*b*c;
	len = getlen(multi);
	
	for(int i=0; i<len; i++)
	{
		int nn = (multi / (int)pow(10.0, len - i - 1)) % 10;
		arr[nn]++;
	}
	
	for(int i=0; i<10; i++)
		cout<<arr[i]<<endl;
	return 0;
}

#include <cstdio>
#include <cmath>

using namespace std;

int count = 0, chk = 0;

int hanoi(int n, char from, char to, char temp)
{
	count++;
	if(n)
	{
		hanoi(n-1, from, temp, to);
		if(chk)
			printf("%c %c\n", from, to);
		hanoi(n-1, temp, to, from);
	}
}

int main(void)
{
	int num;
	long long int num2;
	scanf("%d", &num);
	
	if(num <= 20)
		chk = 1;
		
	if(chk)
		hanoi(num, '1', '3', '2');
		
	else
	{
		num2 = pow(2.0, num) - 1;
		printf("%lld\n",num2);
	}
		
		
	return 0;
}

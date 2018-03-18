#include <iostream>
#include <cmath>
using namespace std;

int get_int_len(int num)
{
	int len = 1;
	while(num /= 10)
		len++;
		
	return len;
}


int main(void)
{
	int testcase;
	cin>>testcase;
	
	for(int tc=0; tc<testcase; tc++)
	{
		int num1, rnum1 = 0, len1, num2, rnum2 = 0, len2 = 1, sum, len3 = 1, answer = 0;
		cin>>num1>>num2;
		
		len1 = get_int_len(num1);
		len2 = get_int_len(num2);
		
		for(int i=0; i<len1; i++)
		{
			int aa = (num1 / (int)(pow(10.0, i))) % 10 * (int)(pow(10.0, len1 - i - 1));
			rnum1 += aa;
		}
		
		for(int i=0; i<len2; i++)
		{
			int aa = (num2 / (int)(pow(10.0, i))) % 10 * (int)(pow(10.0, len2 - i - 1));
			rnum2 += aa;
		}
		
		sum = rnum1 + rnum2;
		
		len3 = get_int_len(sum);
		
		for(int i=0; i<len3; i++)
		{
			int aa = (sum / (int)(pow(10.0, i))) % 10 * (int)(pow(10.0, len3 - i - 1));
			answer += aa;
		}
		
		cout<<answer<<endl;
		
	}
	return 0;
}

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
		int num, rnum = 0, len, sum, slen, chk = 1;
		cin>>num;
		
		len = get_int_len(num);
		
		for(int i=0; i<len; i++)
		{
			int aa = (num / (int)(pow(10.0, i))) % 10 * (int)(pow(10.0, len - i - 1));
			rnum += aa;
		}
		
		sum = num + rnum;
		
		slen = get_int_len(sum);
		for(int i=0; i<slen/2; i++)
		{
			if(sum / (int)pow(10.0, slen - i - 1) % 10 != sum / (int)pow(10.0, i) % 10)
				chk = 0;
		}
		
		if(chk)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

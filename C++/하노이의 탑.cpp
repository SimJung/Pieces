#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class big_int
{
private:
	int data[1000];
	int len;
public:
	big_int(void) : len(1)
	{
		for(int i=0; i<1000; i++)
			data[i] = 0;
	}
	
	big_int(int num) : len(1)
	{
		for(int i=0; i<1000; i++)
			data[i] = 0;
		
		int nn = num;
		while(nn/=10)
			len++;
		
		for(int i=1000-len; i<1000; i++)
			data[i] = (int)(num / pow(10.0, 1000 - i - 1)) % 10;
	}
	
	big_int(string num)
	{
		for(int i=0; i<1000; i++)
			data[i] = 0;
			
		len = num.length();
		for(int i=1000-len; i<1000; i++)
			data[i] = num.at(i - 1000 + len) - 48;
	}
	
	big_int operator+ (big_int n)
	{
		big_int val(0);
		int big_len, chk = 0;
		if(n.len > this->len)
			big_len = n.len;
		else
			big_len = this->len;
			
		for(int i=999; i>1000-big_len-2; i--)
		{
			val.data[i] = n.data[i] + this->data[i];
			if(chk)
			{
				val.data[i]++;
				chk = 0;
			}
			
			if(val.data[i] >= 10)
			{
				chk = 1;
				val.data[i] -= 10;
			}
		}
		
		for(int i=1000 - big_len - 10; i<1000; i++)
		{
			if(val.data[i] != 0)
			{
				val.len = 1000 - i;
				break;
			}
		}
		
		return val;
	}
	
	big_int operator- (big_int n)
	{
		big_int val(0);
		int chk = 0;
			
		for(int i=1000-this->len; i<1000; i++)
		{
			val.data[i] = this->data[i] - n.data[i];
			if(chk)
			{
				val.data[i-1]--;
				chk = 0;
			}
			
			if(val.data[i] < 0)
			{
				chk = 1;
				val.data[i] += 10;
			}
		}
		
		for(int i=1000 - this->len - 10; i<1000; i++)
		{
			if(val.data[i] != 0)
			{
				val.len = 1000 - i;
				break;
			}
		}
		
		return val;
	}
	
	void ShowInfo(void) const
	{
		for(int i=999-len + 1; i<1000; i++)
			cout<<data[i];
		cout<<endl;
	}
};


int hanoi(int n, char start, char dest, char temp)
{
	if(n > 0)
	{
		hanoi(n-1, start, temp, dest);
		printf("%d %d\n", start - 48, dest - 48);
		hanoi(n-1, temp, dest, start);
	}
}

int main(void)
{
	int num;
	
	cin>>num;
	if(num <= 20)
	{
		cout<<pow(2.0, num) - 1<<endl;
		hanoi(num, '1', '3', '2');
	}
	else
	{
		big_int nn("2");
		big_int n1("1");
		for(int i=1; i<num; i++)
			nn = nn + nn;
		
		nn = nn - n1;
		nn.ShowInfo();
	}
	return 0;
}

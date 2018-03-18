#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int getlen(int num)
{
	int len = 1;
	while(num/=10)
		len++;
	return len;
}

int main(void)
{
	string str;
	while(cin>>str && str != "0")
	{
		int num = 10, len;
		while(num >= 10)
		{
			num = 0;
			len = str.length();
			for(int i=0; i<len; i++)
				num += str.at(i) - 48;
			str = "";
			len = getlen(num);
			for(int i=0; i<len; i++)
				str.push_back(((num / (int)pow(10.0, len - i - 1)) % 10) + 48);
		}
		cout<<num<<endl;
	}
	return 0;
}


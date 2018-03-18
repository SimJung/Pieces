#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class bigint
{
private:
	vector<int> num;
	int len;

public:
	bigint() : len(0)
	{
		num.push_back(0);
	}
	
	bigint(int n)
	{
		num.erase(num.begin(), num.end());
		
		if(n != 0)
		{
			len = 1;
			int temp = n;
			while(temp /= 10)
				len++;
			for(int i=0; i<len; i++)
				num.push_back((int)(n / (int)pow(10.0, len - i - 1)) % 10);
		}else{
			len = 0;
			num.push_back(0);
		}
	}
	
	bigint(string s)
	{
		len = s.length();
		num.erase(num.begin(), num.end());
		for(int i = 0; i<len; i++)
			num.push_back(s.at(i) - 48);
	}
	
	bigint(char* s) : bigint((string)s)
	{
	}
	
	bigint& operator= (const string s)
	{
		len = s.length();
		num.erase(num.begin(), num.end());
		for(int i = 0; i<len; i++)
			num.push_back(s.at(i) - 48);
		return *this;
	}
	
	bigint& operator= (const char * c)
	{
		return operator=((string)c);
	}
	
	bigint& operator= (const bigint& b)
	{
		len = b.len;
		num.erase(num.begin(), num.end());
		for(int i = 0; i<len; i++)
			num.push_back(b.num.at(i));
			
		return *this;
	}
	
	bool operator> (const bigint& b)
	{
		if(num.size() > b.num.size())
			return true;
		else if(num.size() < b.num.size())
			return false;
		else
		{
			for(int i=0; i<num.size(); i++)
			{
				if(num.at(i) > b.num.at(i))
					return true;
				else if(num.at(i) < b.num.at(i))
					return false;
			}
			return false;
		}
	}
	
	bool operator< (const bigint& b)
	{
		if(num.size() > b.num.size())
			return true;
		else if(num.size() < b.num.size())
			return false;
		else
		{
			for(int i=0; i<num.size(); i++)
			{
				if(num.at(i) > b.num.at(i))
					return true;
				else if(num.at(i) < b.num.at(i))
					return false;
			}
			return false;
		}
	}
	
	bool operator>= (const bigint& b)
	{
		if(num.size() > b.num.size())
			return true;
		else if(num.size() < b.num.size())
			return false;
		else
		{
			for(int i=0; i<num.size(); i++)
			{
				if(num.at(i) > b.num.at(i))
					return true;
				else if(num.at(i) < b.num.at(i))
					return false;
			}
			return true;
		}
	}
	
	bool operator<= (const bigint& b)
	{
		if(num.size() > b.num.size())
			return true;
		else if(num.size() < b.num.size())
			return false;
		else
		{
			for(int i=0; i<num.size(); i++)
			{
				if(num.at(i) > b.num.at(i))
					return true;
				else if(num.at(i) < b.num.at(i))
					return false;
			}
			return true;
		}
	}
	
	bool operator== (const bigint& b)
	{
		if(num.size() != b.num.size())
			return false;
		else
		{
			for(int i=0; i<num.size(); i++)
			{
				if(num.at(i) != b.num.at(i))
					return false;
			}
			return true;
		}
	}
	
	bool operator!= (const bigint& b)
	{
		if(*this == b)
			return false;
		else
			return true;
	}
	
	bigint operator+ (const bigint& b)
	{
		bigint result, big1, small1;
		int bwall, swall, olim = 0;
		
		if(*this >= b)
		{
			big1 = *this;
			small1 = b;
		}else
		{
			big1 = b;
			small1 = *this;
		}
		
		bwall = big1.num.size() - 1;
		swall = small1.num.size() - 1;
		result.num.erase(result.num.begin(), result.num.end());
		
		for(int i=0; i<=big1.len; i++)
		{
			if(bwall <= -2)
			{
				break;
			}
			
			if(bwall >= 0 && swall >= 0)
				result.num.insert(result.num.begin(), big1.num.at(bwall) + small1.num.at(swall));
			else if(bwall >= 0 && swall < 0)
				result.num.insert(result.num.begin(), big1.num.at(bwall));
				
			
			if(olim)
			{
				if(bwall < 0 && swall < 0)
				{
					result.num.insert(result.num.begin(), 1);
					olim = 0;
				}else
				{
					result.num.at(0)++;
					olim = 0;
				}
			}
			
			if(result.num.at(0) >= 10)
			{
				olim = 1;
				result.num.at(0) -= 10;
			}
			
			bwall--;
			swall--;
		}
		result.len = result.num.size();
		return result;
	}
	
	bigint operator- (const bigint& b)
	{
		bigint result, big1, small1;
		int bwall, swall, nerim = 0;
		
		if(*this >= b)
		{
			big1 = *this;
			small1 = b;
		}else
		{
			big1 = b;
			small1 = *this;
		}
		
		bwall = big1.num.size() - 1;
		swall = small1.num.size() - 1;
		result.num.erase(result.num.begin(), result.num.end());
		
		for(int i=0; i<=big1.len; i++)
		{
			if(bwall <= -1)
			{
				break;
			}
			
			if(bwall >= 0 && swall >= 0)
				result.num.insert(result.num.begin(), big1.num.at(bwall) - small1.num.at(swall));
			else if(bwall >= 0 && swall < 0)
				result.num.insert(result.num.begin(), big1.num.at(bwall));
				
			
			if(nerim)
			{
				result.num.at(0)--;
				nerim = 0;
			}
			
			if(result.num.at(0) < 0)
			{
				nerim = 1;
				result.num.at(0) += 10;
			}
			
			bwall--;
			swall--;
		}
		
		if(big1 != small1)
		{
			for(int i=0; i<big1.len; i++)
			{
				if(result.num.at(i) == 0)
					result.num.erase(result.num.begin() + i);
				else
					break;
			}
		}else
		{
			result.num.erase(result.num.begin(), result.num.end());
			result.num.push_back(0);
		}
		
		
		result.len = result.num.size();
		return result;
	}
	
	int getlen() const { return len; }
	
	friend ostream& operator<< (ostream& os, const bigint& b);
	friend istream& operator>> (istream& is, bigint& b);
};

ostream& operator<< (ostream& os, const bigint& b)
{
	for(int i=0; i<b.num.size(); i++)
		os<<b.num[i];
	
	return os;
}

istream& operator>> (istream& is, bigint& b)
{
	string str;
	is>>str;
	b = str;
	return is; 
}

int main(void)
{
	bigint a = "101";
	
	bigint b = 548979879;
	
	cout<<a-b<<' '<<endl;
	return 0;
}

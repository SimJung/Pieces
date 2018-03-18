#include <iostream>
#include <string>
#include <vector>
using namespace std;

int strcmp(string a, string b)
{
	if(a.length() > b.length())
		return 1;
		
	else if(a.length() == b.length())
	{
		for(int i=0; i<a.length(); i++)
		{
			if(a[i] > b[i])
				return 1;
			else if(a[i] < b[i])
				return 0;
		}
	}
	return 0;
	
}

int main(void)
{
	int num;
	cin>>num;
	
	string * str_arr = new string [num]; 
	vector<string> num_vec;
	string num_str = "";
	
	for(int numnum = 0; numnum<num; numnum++) cin>>str_arr[numnum];
	
	bool chk_zero = 0;
	bool chk_num = 0;
	int noe = 0;
	
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<str_arr[i].length(); j++)
		{
			if(str_arr[i][j] == 48)
			{
				if(chk_zero)
				{
					if(str_arr[i][j+1]>=97)
					{
						num_str.push_back(str_arr[i][j]);
						chk_zero = 0;
						num_vec.push_back(num_str);
						num_str = "";
						noe++;
					}else if(!(chk_num) && j == str_arr[i].length() - 1)
					{
						num_str.push_back(str_arr[i][j]);
						chk_zero = 0;
						num_vec.push_back(num_str);
						num_str = "";
						noe++;
					}
				}else if(!(chk_num) && j == str_arr[i].length() - 1)
				{
					num_vec.push_back("0");
					noe++;
				}
				else if(j == 0 || str_arr[i][j-1]>=97)
				{
					chk_zero = 1;
				}else if(chk_num)
				{
					if(j == str_arr[i].length() - 1)
					{
						num_str.push_back(str_arr[i][j]);
						chk_num = 0;
						num_vec.push_back(num_str);
						num_str = "";
						noe++;
					}else
						num_str.push_back(str_arr[i][j]);
				}
					
			}else if(str_arr[i][j] >= 49 && str_arr[i][j] <= 57)
			{
				chk_zero = 0;
				num_str.push_back(str_arr[i][j]);
				chk_num = 1;
				if(j == str_arr[i].length() - 1 && chk_num)
				{
					num_vec.push_back(num_str);
					num_str = "";
					chk_num = 0;
					noe++;
				}
			}else
			{
				if(chk_num)
				{
					num_vec.push_back(num_str);
					num_str = "";
					chk_num = 0;
					noe++;
				}else if(chk_zero)
				{
					num_vec.push_back("0");
					chk_zero = 0;
					noe++;
				}
			}
		}
	}
	
	string swap;
	
	for(int i=0; i<noe - 1; i++)
	{
		for(int j=i+1; j<noe; j++)
		{
			if(strcmp(num_vec[i], num_vec[j]) > 0)
			{
				swap = num_vec[i];
				num_vec[i] = num_vec[j];
				num_vec[j] = swap;
			}
		}
	}
	
	cout<<endl<<endl<<endl;
	
	for(int i=0; i<noe; i++)
	{
		cout<<'\t'<<num_vec[i]<<endl;
	}
	return 0;
}

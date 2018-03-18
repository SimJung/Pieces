#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<string> str_arr;
	string indi;
	int wall = 0, noe = 1;
	
	str_arr.push_back("http://www.acm.org/");
	
	while(indi != "QUIT")
	{
		if(indi == "VISIT")
		{
			wall++;
			
			string url;
			cin>>url;
			
			if(wall < noe)
			{
				str_arr.at(wall) = url;
				
				for(int i=wall+1; i<noe; i++)
				{
					str_arr.at(i) = "";
				}
				
				noe = wall + 1;
				
				cout<<str_arr.at(wall)<<endl;
			}else if(wall == noe)
			{
				if(str_arr.size() <= wall)
					str_arr.push_back(url);
				else
					str_arr.at(wall) = url;
					
				noe++;
				cout<<str_arr.at(wall)<<endl;
			}else if(wall > noe)
			{
				wall--;
				str_arr.push_back(url);
				noe++;
				cout<<str_arr.at(wall)<<endl;
			}
		}else if(indi == "BACK")
		{
			if(wall == 0)
			{
				cout<<"Ignored"<<endl;
			}
			else
			{
				wall--;
				cout<<str_arr.at(wall)<<endl;
			}
		}else if(indi == "FORWARD")
		{
			if(wall >= noe - 1)
			{
				cout<<"Ignored"<<endl;
			}
			else
			{
				wall++;
				cout<<str_arr.at(wall)<<endl;
			}
		}
		
		cin>>indi;
	}
	
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

void PrintError(void)
{
	cout<<"Error!"<<endl;
}

enum{cpp, java};

int main(void)
{
	int chk_type = cpp, wall = 0, chk_coj = 0; 
	string a, b = "";
	cin>>a;
	
	if(a[0] == '_')
	{
		PrintError();
		return 0;
	}
	
	if(a[0] >=65 && a[0] <= 90 )
	{
		PrintError();
		return 0;
	}
	
	if(a[a.length() - 1] == '_')
	{
		PrintError();
		return 0;
	 }
	
	for(int i=0; i<a.length(); i++)
	{
		if(a[i] >= 65 && a[i] <= 90)
			chk_coj = 1;
			
		if(a[i] == '_' && chk_coj)
		{
			PrintError();
			return 0;
		}
		
		if(a[i] == '_')
		{
			if(a[i + 1] == '_')
			{
				PrintError();
				return 0;
			}
		}
		
		if(a[i] >= 123)
		{
			PrintError();
			return 0;
		}
		
		if(a[i] >=91 && a[i] <=96 && a[i] != '_')
		{
			PrintError();
			return 0;
		}
	}
	
	for(int i=0; i<a.length(); i++)
	{
		if(a[i] <= 64)
		{
			PrintError();
			return 0;
		}
		
		if(a[i] == '_')
		{
			chk_type = java;
		}
		
		if(chk_type == java && a[i] <=90)
		{
			PrintError();
			return 0;
		}		
	}
	
	if(chk_type == cpp)
	{
		while(a[wall]!='\0')
		{
			if(a[wall] <= 90 && a[wall] >=65)
			{
				a.insert(wall, "_");
				a[wall + 1] += 32;
				wall++;
			}
			wall++;
		} 
	}else if(chk_type == java)
	{
		while(a[wall]!='\0')
		{
			if(a[wall] == '_')
			{
				a.erase(wall, 1);
				a[wall] -= 32;
				wall--;
			}
			wall++;
		} 
	}
	
	cout<<a<<endl;
	
	return 0;
}

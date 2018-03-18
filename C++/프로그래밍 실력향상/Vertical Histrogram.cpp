#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string a,b,c,d;
	
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);
	getline(cin, d);
	
	int arr[26] = {0, }, max = 0;
	
	for(int i=0; i<a.length(); i++)
	{
		if(a.at(i) >= 65 && a.at(i) <= 90)
			arr[a.at(i)-65]++;
	}
		
	
	for(int i=0; i<b.length(); i++)
	{
		if(b.at(i) >= 65 && b.at(i) <= 90)
			arr[b.at(i)-65]++;
	}
		
	for(int i=0; i<c.length(); i++)
	{
		if(c.at(i) >= 65 && c.at(i) <= 90)
			arr[c.at(i)-65]++;
	}
			
		
	for(int i=0; i<d.length(); i++)
	{
		if(d.at(i) >= 65 && d.at(i) <= 90)
			arr[d.at(i)-65]++;
	}
			
	
	for(int i=0; i<26; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	
	for(int i=max; i>0; i--)
	{
		for(int j=0; j<26; j++)
		{
			if(arr[j] >= i)
				cout<<"*";
			else
				cout<<" ";
				
			cout<<" ";
		}
		cout<<endl;
	}
	
	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
	
	return 0;
}

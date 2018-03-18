#include <iostream>

using namespace std;

int main(void)
{
	int a, b;
	
	while((cin>>a>>b) && a && b)
	{
		char **tiles = new char*[a];
		for(int i=0; i<a; i++)
		{
			tiles[i] = new char[b];
		}
		
		for(int i=0; i<b; i++)
			cin>>tiles[i];
			
		for(int i=0; i<b; i++)
			cout<<tiles[i]<<endl;
	}
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

void mk_arr()
{
	
}

int main(void)
{
	int tc;
	cin>>tc;
	
	for(int i=0; i<tc; i++)
	{
		unsigned int num, root;
		cin>>num;
		
		for(int j=0; j<33; j++)
		{
			if((int)pow(2.0, j) >= num)
				root = j;
		}
		unsigned int *arr = ;	
	}
	return 0;
}

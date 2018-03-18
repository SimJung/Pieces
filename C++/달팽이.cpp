#include <iostream>
using namespace std;

int main(void)
{
	int x = 0, y = 0, num, key, keyx, keyy;
	const int nn = num;
	cin>>num>>key;
	
	int **arr = new int *[num];
	
	for(int i=0; i<num; i++)
	{
		arr[i] = new int [num];
	}
	
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<num; j++)
			arr[i][j] = 0;
	}
	
	for(int i=num*num; i>0; i--)
	{
		arr[y][x] = i;
		
		if(arr[y][x] == key)
		{
			keyx = x;
			keyy = y;
		}
		
		if(y < num-1 && !(arr[y+1][x]))
		{
			if(x >= 1)
			{
				if(arr[y][x-1])
					y++;
				else
					x--;
			}else
				y++;		
		}
		else if(x < num-1 && !(arr[y][x+1]))
			x++;
		else if(y > 0 && !(arr[y-1][x]))
			y--;
		else if(x > 0 && !(arr[y][x-1]))
			x--;
			
	}
	
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<num; j++)
		{
			printf("%5d ", arr[i][j]);
		}
		printf("\n");
	}
	
	cout<<keyy+1<<' '<<keyx+1<<endl;
	
	return 0;
}

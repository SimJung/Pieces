#include <iostream>

using namespace std;

int min(int a, int b)
{
	if(a > b) return b;
	else return a;
}

int main(void)
{
	int num;
	cin>>num;
	
	int **arg = new int * [num];
	int **val_arg = new int * [num];
	for(int i=0; i<num; i++)
	{
		arg[i] = new int[3];
		val_arg[i] = new int[3];
	}
	
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin>>arg[i][j];
			val_arg[i][j] = 0;
		}
	}
	
	val_arg[0][0] = arg[0][0];
	val_arg[0][1] = arg[0][1];
	val_arg[0][2] = arg[0][2];
	
	for(int i=1; i<num; i++)
	{
		val_arg[i][0] = arg[i][0] + min(val_arg[i-1][1], val_arg[i-1][2]);
		val_arg[i][1] = arg[i][1] + min(val_arg[i-1][0], val_arg[i-1][2]);
		val_arg[i][2] = arg[i][2] + min(val_arg[i-1][0], val_arg[i-1][1]);
	}
	
	if(min(val_arg[num-1][0], val_arg[num-1][1]) >= val_arg[num-1][2])
		cout<<val_arg[num-1][2];
	else
		cout<<min(val_arg[num-1][0], val_arg[num-1][1])<<endl;
	
	return 0;
}

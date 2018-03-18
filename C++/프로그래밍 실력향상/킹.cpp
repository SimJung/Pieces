#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int field[8][8] = {0, };
	
	string kingloca, stoneloca;
	int tc, kx, ky, sx, sy;
	
	cin>>kingloca>>stoneloca>>tc;
	
	ky = 56 - kingloca.at(1);
	kx = kingloca.at(0) - 65;
	
	sy = 56 - stoneloca.at(1);
	sx = stoneloca.at(0) - 65;
	
	field[ky][kx] = 1;
	field[sy][sx] = 2;
	
	for(int i=0; i<tc; i++)
	{
		int chk = 1;
		string indi;
		cin>>indi;
		
		if(indi == "R")
		{
			if(kx + 1 == sx && ky == sy)
			{
				if(sx + 1 >= 8)
				{
					chk = 0;
				}
				else if(chk){
					field[ky][kx] = 0;
					field[sy][sx] = 0;
					
					kx++;
					sx++;
					
					field[ky][kx] = 1;
					field[sy][sx] = 2;
				}
			}else if(kx + 1 >= 8)
			{
				chk = 0;
			}
			else if(chk)
			{
				field[ky][kx] = 0;
				
				kx++;
				
				field[ky][kx] = 1;
			}
		}else if(indi == "L")
		{
			if(kx - 1 == sx && ky == sy)
			{
				if(sx - 1 <= -1)
				{
					chk = 0;
				}
				else if(chk){
					field[ky][kx] = 0;
					field[sy][sx] = 0;
					
					kx--;
					sx--;
					
					field[ky][kx] = 1;
					field[sy][sx] = 2;
				}
			}else if(kx - 1 <= -1)
			{
				chk = 0;
			}
			else if(chk)
			{
				field[ky][kx] = 0;
				
				kx--;
				
				field[ky][kx] = 1;
			}
		}else if(indi == "B")
		{
			if(kx == sx && ky + 1 == sy)
			{
				if(sy + 1 >= 8)
				{
					chk = 0;
				}
				else if(chk){
					field[ky][kx] = 0;
					field[sy][sx] = 0;
					
					ky++;
					sy++;
					
					field[ky][kx] = 1;
					field[sy][sx] = 2;
				}
			}else if(ky + 1 >= 8)
			{
				chk = 0;
			}
			else if(chk)
			{
				field[ky][kx] = 0;
				
				ky++;
				
				field[ky][kx] = 1;
			}
		}else if(indi == "T")
		{
			if(kx == sx && ky - 1 == sy)
			{
				if(sy - 1 <= -1)
				{
					chk = 0;
				}
				else if(chk){
					field[ky][kx] = 0;
					field[sy][sx] = 0;
					
					ky--;
					sy--;
					
					field[ky][kx] = 1;
					field[sy][sx] = 2;
				}
			}else if(ky - 1 <= -1)
			{
				chk = 0;
			}
			else if(chk)
			{
				field[ky][kx] = 0;
				
				ky--;
				
				field[ky][kx] = 1;
			}
		}else if(indi == "RT")
		{
			if(kx + 1 == sx && ky - 1 == sy)
			{
				if(sy - 1 <= -1 || sx + 1 >= 8)
				{
					chk = 0;
				}
				else if(chk){
					field[ky][kx] = 0;
					field[sy][sx] = 0;
					
					kx++;
					sx++;
					
					ky--;
					sy--;
					
					field[ky][kx] = 1;
					field[sy][sx] = 2;
				}
			}else if(ky - 1 <= -1 || kx + 1 >= 8)
			{
				chk = 0;
			}
			else if(chk)
			{
				field[ky][kx] = 0;
				
				ky--;
				kx++;
				
				field[ky][kx] = 1;
			}
		}else if(indi == "LT")
		{
			if(kx - 1 == sx && ky - 1 == sy)
			{
				if(sy - 1 <= -1 || sx - 1 <= -1)
				{
					chk = 0;
				}
				else if(chk){
					field[ky][kx] = 0;
					field[sy][sx] = 0;
					
					kx--;
					sx--;
					
					ky--;
					sy--;
					
					field[ky][kx] = 1;
					field[sy][sx] = 2;
				}
			}else if(ky - 1 <= -1 || kx - 1 <= -1)
			{
				chk = 0;
			}
			else if(chk)
			{
				field[ky][kx] = 0;
				
				ky--;
				kx--;
				
				field[ky][kx] = 1;
			}
		}else if(indi == "RB")
		{
			if(kx + 1 == sx && ky + 1 == sy)
			{
				if(sy + 1 >= 8 || sx + 1 >= 8)
				{
					chk = 0;
				}
				else if(chk){
					field[ky][kx] = 0;
					field[sy][sx] = 0;
					
					kx++;
					sx++;
					
					ky++;
					sy++;
					
					field[ky][kx] = 1;
					field[sy][sx] = 2;
				}
			}else if(ky + 1 >= 8 || kx + 1 >= 8)
			{
				chk = 0;
			}
			else if(chk)
			{
				field[ky][kx] = 0;
				
				ky++;
				kx++;
				
				field[ky][kx] = 1;
			}
		}else if(indi == "LB")
		{
			if(kx - 1 == sx && ky + 1 == sy)
			{
				if(sy + 1 >= 8 || sx - 1 <= -1)
				{
					chk = 0;
				}
				else if(chk){
					field[ky][kx] = 0;
					field[sy][sx] = 0;
					
					kx--;
					sx--;
					
					ky++;
					sy++;
					
					field[ky][kx] = 1;
					field[sy][sx] = 2;
				}
			}else if(ky + 1 >= 8 || kx - 1 <= -1)
			{
				chk = 0;
			}
			else if(chk)
			{
				field[ky][kx] = 0;
				
				ky++;
				kx--;
				
				field[ky][kx] = 1;
			}
		}
	}
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			if(field[i][j] == 1)
			{
				cout<<(char)(65 + j)<<8-i<<endl;
				break;
			}	
		}
	}
	
		for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			if(field[i][j] == 2)
			{
				cout<<(char)(65 + j)<<8-i<<endl;
				break;
			}	
		}
	}
	return 0;
}

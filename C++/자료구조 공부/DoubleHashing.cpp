#include <iostream>
#define SIZE_OF_TABLE 256
using namespace std;

short hash_M1(short k)
{
	return k & 255;
}
	
short hash_M2(short k)
{
	return (k & 65280) | 1;
}



class hash_table
{
private:
	short table[SIZE_OF_TABLE];
	
public:
	
	
	

};

int main(void)
{
	return 0;
}

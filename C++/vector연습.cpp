#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> cons;
	
	cout<<cons.size()<<endl;
	
	cons.push_back(3);
	
	cout<<cons[0]<<endl;
	cout<<cons.size()<<endl;
	
	return 0;
}

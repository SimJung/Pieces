#include <iostream>
using namespace std;

template <class T = int, int len = 5>
class SimpleArray
{
private:
	T arr[len];
	
public:
	T& operator[] (int idx) { return arr[idx]; }
	SimpleArray<T, len>& operator= (const SimpleArray<T, len>& ref)
	{
		for(int i=0; i<len; i++)
			arr[i] = ref.arr[i];
		return *this;
	}	
};

int main(void)
{
	SimpleArray<> inumarray;
	for(int i=0; i<5; i++)
	{
		inumarray[i] = i+1;
		cout<<inumarray[i]<<' ';
	}
	cout<<endl;
	return 0;
}

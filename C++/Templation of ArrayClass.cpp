#include <iostream>
using namespace std;

template <class T>
class BoundCheckArray
{
private:
	T *arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) { }
	BoundCheckArray& operator= (const BoundCheckArray& arr) { }
	
public:
	BoundCheckArray(int len) : arrlen(len)
	{
		arr = new T[len];
	}
	
	T& operator[] (int idx)
	{
		if(idx < 0 || idx >= arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}else
		{
			return arr[idx];
		}
	}
	
	T operator[] (int idx) const
	{
		if(idx < 0 || idx >= arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}else
		{
			return arr[idx];
		}
	}
	
	int getArrlen() const { return arrlen; }
	
	~BoundCheckArray() { delete []arr; }
};

int main(void)
{
	BoundCheckArray<int> int_arr(5);
	BoundCheckArray<double> double_arr(5);
	BoundCheckArray<char> char_arr(5);
	for(int i=1; i<=5; i++)
	{
		int_arr[i-1] = i;
		double_arr[i-1] = i + (double)i/10.0;
		char_arr[i-1] = i+64;
	}
	
	for(int i=0; i<5; i++)
		cout<<int_arr[i]<<endl;
	
	for(int i=0; i<5; i++)
		cout<<double_arr[i]<<endl;
		
	for(int i=0; i<5; i++)
		cout<<char_arr[i]<<endl;
	
	return 0;
}

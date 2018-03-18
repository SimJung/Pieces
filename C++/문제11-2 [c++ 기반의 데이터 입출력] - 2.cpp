#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int * arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator= (const BoundCheckIntArray& arr) { }
	
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int [len];
	}	
	
	int& operator [] (int idx)
	{
		if(idx < 0 || idx >= arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return arr[idx];
	}
	
	int operator [] (int idx) const
	{
		if(idx < 0 || idx >= arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return arr[idx];
	}
	int GetArrLen() const {return arrlen;}
	~BoundCheckIntArray() {delete []arr;}
};

class BoundCheck2DIntArray
{
private:
	BoundCheckIntArray **arr;
	int height;
	
	BoundCheck2DIntArray(const BoundCheck2DIntArray&) {	}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray&) { };
	
public:
	BoundCheck2DIntArray(int h, int w) : height(h)
	{
		arr = new BoundCheckIntArray*[h];
		for(int i=0; i<h; i++)
			arr[i] = new BoundCheckIntArray(w);
	}
	
	BoundCheckIntArray& operator[] (int idx)
	{
		if(idx < 0 || height <= idx)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return *(arr[idx]);
	}
	
	~BoundCheck2DIntArray() {
		for(int i=0; i<height; i++)
			delete []arr;
	}
	
};

int main(void)
{
	BoundCheck2DIntArray arr(3, 4);
	
	for(int i=0; i<3; i++)
		for(int j=0; j<4; j++)
			arr[i][j] = i*4+j;
			
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
			cout<<arr[i][j]<<'\t';
		cout<<endl;
	}
	
	return 0;
}

#include <iostream>
#include <cstdlib>
#define MIN_ARR 4
using namespace std;


void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int selmid(int a, int b, int c)
{
	if(a >= b)
	{
		if(b >= c)
			return b;
		else if(a >= c)
			return c;
	}else{
		if(a >= c)
			return a;
		else if(b >= c)
			return c;
	}
}


void insertion_sort(int *array, int first, int last)
{
	for(int i=first; i<=last; i++)
	{
		for(int j=i; j<=last; j++)
		{
			if(array[i] > array[j])
				swap(array[i], array[j]);	
		}	
	}
}

void quick_sort(int *array, int first, int mid, int last)
{
	if(last - first <= MIN_ARR)
		insertion_sort(array, first, last);
	else{
		int i1 = first, i2 = last-1, temp = selmid(array[first], array[mid], array[last]);
		
		
		if(temp == array[first])
			swap(array[first], array[last]);
			
		else if(temp == array[mid])
			swap(array[mid], array[last]);
		
				
		while(i1 < i2)
		{
			if(array[i1] <= temp)
				i1++;
			
			if(array[i2] >= temp)
				i2--;
				
			if(i1 >= i2)
				break;
			
			if(array[i1] > temp && array[i2] < temp) {
				swap(array[i1], array[i2]);
			}
			
		}
		
		swap(array[i1], array[last]);
		
		quick_sort(array, first, (first+i1-1)/2, i1-1);
		quick_sort(array, i1+1, (i1+1+last)/2, last);
		
		
	}
}

int main(void)
{
	int arr[30];
	for(int i=0; i<30; i++)
		arr[i] = rand() % 100 + 1;
	
	for(int i=0; i<30; i++)
		cout<<arr[i]<<' ';
	cout<<endl;
	
	quick_sort(arr, 0, 15, 29);
	
	for(int i=0; i<30; i++)
		cout<<arr[i]<<' ';
	cout<<endl;
	return 0;
}

#include <iostream>
#define NUM_OF_MIN 4

using namespace std;

int arrayout[10];

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void insertion_sort(int *array, int first, int last)
{
	for(int i=first; i<last; i++)
	{
		for(int j=i; j<last; j++)
		{
			if(array[i] > array[j])
				swap(array[i], array[j]);	
		}	
	}
}

void merge(int *array, int first, int mid, int last)
{

	int n = 5, i1 = first, i2 = mid , k = 0;

	while ( i1 < n && i2 < 10 ) {
	    if ( array[i1] < array[i2] ) {
	        arrayout[k] = array[i1];
	        ++i1;
	    } else {
	        arrayout[k] = array[i2];
	        ++i2;
	    }
	    ++k;
	}
	
	for ( ; i1 < n; ++i1, ++k ) {
	    arrayout[k] = array[i1];
	}

	for ( ; i2 < 10; ++i2, ++k ) {
	    arrayout[k] = array[i2]; 
	}
	
	
	for(int i=0; i<10; i++)
		array[i] = arrayout[i];
		
}


void merge_sort(int *array, int first, int last)
{
	if(last - first <= NUM_OF_MIN)
		insertion_sort(array, first, last);
	else {
		int midpoint = (first+last)/2;
		
		merge_sort(array, first, midpoint);
		merge_sort(array, midpoint+1, last);
		
		merge(array, first, midpoint, last);
		
	}
}

int main(void)
{
	int array[10] = {3, 7, 5, 9, 10, 4, 6, 8, 1, 2};
	
	
	merge_sort(array, 0, 10);
	
	for(int i=0; i<10; i++)
		cout<<array[i]<<' ';
	cout<<endl;
}
